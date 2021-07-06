#include "inbox_message_dialog.h"

InboxMessageDialog::InboxMessageDialog() = default;

InboxMessageDialog::InboxMessageDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

InboxMessageDialog::InboxMessageDialog(const InboxMessageDialog &o) = default;

InboxMessageDialog::~InboxMessageDialog() = default;

botserver::spBotResponse InboxMessageDialog::handleMessage(botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("InboxMessageDialog::handleMessage");

  // TODO: Перемещать пользователя на следующий диалог

  const auto &client = request->getClient();
  const string &msg = getMessage();

  //client->

  return botserver::BotResponse::makeResponse(msg);
}
