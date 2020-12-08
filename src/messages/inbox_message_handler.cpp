#include <iostream>
#include "inbox_message_handler.h"

using namespace std;

InboxMessageHandler ::InboxMessageHandler() = default;

InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

InboxMessageHandler ::~InboxMessageHandler() = default;

spBotResponse InboxMessageHandler::onMessageHandler(const char* data)
{
  DEBUG_STRUCT_LOG("Message type 1, onInboxMessageHandler()");

  return BotResponse::makeResponse("InboxMessageHandler message");
}
