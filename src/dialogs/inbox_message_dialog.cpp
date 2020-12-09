#include "inbox_message_dialog.h"

InboxMessageDialog::InboxMessageDialog() = default;

InboxMessageDialog::InboxMessageDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

InboxMessageDialog::InboxMessageDialog(const InboxMessageDialog &o) = default;

InboxMessageDialog::~InboxMessageDialog() = default;

spBotResponse InboxMessageDialog::HandleMessage(spClient &client, spUserInboxMessage &msg) const
{
  DEBUG_STRUCT_LOG("InboxMessageDialog::HandleMessage");

  return BotResponse::makeResponse(GetMessage());
}
