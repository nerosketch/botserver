#include <httplib.h>
#include "http_server.h"
#include <messages/msg_map.h>

httplib::Server _svr;


LocalHttpServer::LocalHttpServer()
= default;

LocalHttpServer::~LocalHttpServer()
= default;


void LocalHttpServer::stopSignal()
{
  _svr.stop();
}

const httplib::Server::Handler entrypoint_handler = [](const httplib::Request &request, httplib::Response &res)
{

  auto msg_type = request.get_header_value<uint64_t>("bot-message-type");

  const auto &msg_map_it = MessageTypeMap.find(msg_type);
  if (msg_map_it == MessageTypeMap.end())
  {
    // message not found;
    cerr << "Unexpected message type: " << msg_type << endl;
    return;
  }

  const auto& msg_creator_if = msg_map_it->second;
  const auto& msg_interface = msg_creator_if->createInst();
  auto response = msg_interface->onMessageHandler(request.body);

  const string response_text = response->getJsonString();

  res.set_content(response_text, "application/json");
};


spError LocalHttpServer::Serve(const char *host, int port, int socket_flags)
{
  // HTTPS
  //httplib::SSLServer svr;

  _svr.Post("/entrypoint/", entrypoint_handler);

  if (!_svr.listen(host, port))
  {
    return Error::makeError("Error listen http", 0);
  }

  return nullptr;
}
