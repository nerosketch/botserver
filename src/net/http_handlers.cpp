#include <string>
#include <messages/msg_map.h>
#include <core/request.h>
#include "http_handlers.h"

using namespace std;

httplib::Server::Handler entrypoint_handler = [](const httplib::Request &request, httplib::Response &res)
{
  botserver::spRequest bot_request = make_shared<botserver::Request>();

  bot_request->setHttpRequestPtr(&request);

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
  auto response = msg_interface->onMessageHandler(request.body, bot_request);

  if (!response)
  {
    res.status = 500;
    res.set_content("Server Error", "application/json");
    return;
  }

  const string response_text = response->getJsonString();

  res.set_content(response_text, "application/json");
};
