#include <iostream>
#include <memory.h>
#include "server.h"
#include "../third_party/tcp_server.h"
#include "../messages/msg_map.h"
#include "bot_response.h"

using namespace std;

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
    // not found;
    cout << "Unexpected message type: " << hdr->message_type << endl;
    return nullptr;
  }

  spUserInboxMessage msg = UserInboxMessage::parseFromBytes(len, data);

  const auto& msg_creator_if = msg_map_it->second;
  const auto& msg_int = msg_creator_if->createInst();
  return msg_int->onMessageHandler(msg);
}

spErrorBase Serve(in_port_t port)
{
  //Создание объекта TcpServer с передачей аргументами порта и лябда-фунции для обработк клиента
  TcpServer server(port,

                   [](TcpServer::Client client) {
                     //Вывод адреса подключившего клиента в консоль
                     cout << "Connected host:" << getHostStr(client) << endl;

                     //Ожидание данных от клиента
                     ssize_t size = 0;
                     while (!(size = client.loadData()));

                     //Вывод размера данных и самих данных в консоль
                     cout
                         << "size: " << size << " bytes" << endl
                         << client.getData() << endl;

                     const auto response = handleConnection(size, client.getData());

                     //Отправка ответа клиенту
                     //  const char answer[] = "Hello World from Server";
                     //  client.sendData(answer, sizeof(answer));
                     const auto& response_text = response->GetText();
                     client.sendData(response_text.c_str(), response_text.length());
                   }

  );

  //Запуск серевера
  if (server.start() == TcpServer::status::up)
  {
    //Если сервер запущен вывести сообщение и войти в поток ожиданий клиентов
    cout << "Server is up!" << endl;
    server.joinLoop();
  }
  else
  {
    //Если сервер не запущен вывод кода ошибки и заверешение программы
    cout << "Server start error! Error code:" << int(server.getStatus()) << endl;
    return ErrorBase::makeError("Server start error!", int(server.getStatus()));
  }
  return nullptr;
}
