#include <iostream>
#include "inbox_message_handler.h"

using namespace std;

InboxMessageHandler ::InboxMessageHandler() = default;

InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

InboxMessageHandler ::~InboxMessageHandler() = default;

spBotResponse InboxMessageHandler::onMessageHandler(const char* data)
{
  cout << "Message type 1, onInboxMessageHandler()" << endl;
  return make_shared<BotResponse>("InboxMessageHandler message");
}
