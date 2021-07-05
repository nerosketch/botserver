#include "inbox_message_dialog.h"

InboxMessageDialog::InboxMessageDialog() = default;

InboxMessageDialog::InboxMessageDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

InboxMessageDialog::InboxMessageDialog(const InboxMessageDialog &o) = default;

InboxMessageDialog::~InboxMessageDialog() = default;

spBotResponse InboxMessageDialog::HandleMessage(botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("InboxMessageDialog::HandleMessage");

  // TODO: Перемещать пользователя на следующий диалог

  const spClient &client = request->getClient();
  const string &msg = getMessage();

  //client->

  return BotResponse::makeResponse(msg);
}
