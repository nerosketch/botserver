#include <iostream>
#include <memory.h>
#include "server.h"
#include "../messages/msg_map.h"
#include "bot_response.h"

using namespace std;


SockServer::SockServer() : p_server(nullptr)
{
  DEBUG_STRUCT_LOG("SockServer::SockServer()");
}

SockServer::SockServer(const SockServer& o)
= default;

SockServer::~SockServer()
{
  DEBUG_STRUCT_LOG("SockServer::~SockServer()");

  if (p_server != nullptr)
  {
    delete p_server;
  }
}




//Парсер ip в string
string getHostStr(const TcpServer::Client &client)
{
  in_addr_t ip = client.getHost();
  return string() + to_string(int(reinterpret_cast<char *>(&ip)[0])) + '.' +
         to_string(int(reinterpret_cast<char *>(&ip)[1])) + '.' +
         to_string(int(reinterpret_cast<char *>(&ip)[2])) + '.' +
         to_string(int(reinterpret_cast<char *>(&ip)[3])) + ':' +
         to_string(client.getPort());
}

#pragma pack(push, 1)
typedef struct
{
  uint16_t message_type;
} _message_type_struct;
#pragma pack(pop)

spBotResponse handleConnection(ssize_t len, const char *data)
{
  _message_type_struct *hdr = (_message_type_struct *)data;

  const auto &msg_map_it = MessageTypeMap.find(hdr->message_type);
  if (msg_map_it == MessageTypeMap.end())
  {
    // message not found;
    return BotResponse::makeResponse("Unexpected message type: " + to_string(hdr->message_type));
  }

  if (len > sizeof(uint16_t))
  {
    data += sizeof(uint16_t);

    const auto& msg_creator_if = msg_map_it->second;
    const auto& msg_int = msg_creator_if->createInst();
    return msg_int->onMessageHandler(len, data);
  }
  return nullptr;
}

spErrorBase SockServer::Serve(in_port_t port)
{
  //Создание объекта TcpServer с передачей аргументами порта и лябда-фунции для обработк клиента
  p_server = new TcpServer(port,

                   [](TcpServer::Client client) {
                     //Вывод адреса подключившего клиента в консоль
                     cout << "Connected host:" << getHostStr(client) << endl;

                     //Ожидание данных от клиента
                     ssize_t size = 0;
                     while (!(size = client.loadData()));

#ifdef DEBUG
                     //Вывод размера данных и самих данных в консоль
                     cout
                         << "Size: " << size << " bytes" << endl
                         << "Data: " << client.getData()+2 << endl;
#endif

                     const auto response = handleConnection(size, client.getData());
                     if (!response)
                     {
                       const string null_ret("null");
                       client.sendData(null_ret.c_str(), null_ret.length());
                       return;
                     }

                     //Отправка ответа клиенту
                     //  const char answer[] = "Hello World from Server";
                     //  client.sendData(answer, sizeof(answer));
                     DEBUG_STRUCT_LOG("Pre Out client data");
                     const auto response_text = response->getJsonString();

                     DEBUG_STRUCT_LOG("Out client data");
                     DEBUG_STRUCT_LOG(response_text);
                     client.sendData(response_text.c_str(), response_text.length());
                   }

  );

  //Запуск серевера
  if (p_server->start() == TcpServer::status::up)
  {
    //Если сервер запущен вывести сообщение и войти в поток ожиданий клиентов
    cout << "Server is up! Listening..." << endl;
    p_server->joinLoop();
  }
  else
  {
    //Если сервер не запущен вывод кода ошибки и заверешение программы
    #ifdef DEBUG
    cout << "Server start error! Error code:" << int(p_server->getStatus()) << endl;
    #endif

    delete p_server;
    p_server = nullptr;
    return ErrorBase::makeError("Server start error!", int(p_server->getStatus()));
  }

  delete p_server;
  p_server = nullptr;

  return nullptr;
}
