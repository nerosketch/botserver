#include "start_messaging_dialog.h"

StartMessagingDialog::StartMessagingDialog() = default;

StartMessagingDialog::StartMessagingDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

StartMessagingDialog::StartMessagingDialog(const StartMessagingDialog &o) = default;

StartMessagingDialog::~StartMessagingDialog() = default;

spBotResponse StartMessagingDialog::HandleMessage(spClient &client, spUserInboxMessage &msg) const
{
  DEBUG_STRUCT_LOG("StartMessagingDialog::HandleMessage");

  return BotResponse::makeResponse(GetMessage());
}
