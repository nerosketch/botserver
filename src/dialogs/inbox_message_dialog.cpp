#include "inbox_message_dialog.h"

InboxMessageDialog::InboxMessageDialog() = default;

InboxMessageDialog::InboxMessageDialog(const InboxMessageDialog &o) = default;

InboxMessageDialog::~InboxMessageDialog() = default;

spBotResponse InboxMessageDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
  DEBUG_STRUCT_LOG("InboxMessageDialog::HandleMessage");

  return BotResponse::makeResponse("Inbox msg dialog response");
}
