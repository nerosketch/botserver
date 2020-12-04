#include "inbox_message_handler.h"

InboxMessageHandler ::InboxMessageHandler() = default;

InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

InboxMessageHandler ::~InboxMessageHandler() = default;

spErrorBase InboxMessageHandler::onMessageHandler(spUserInboxMessage &msg)
{
}
