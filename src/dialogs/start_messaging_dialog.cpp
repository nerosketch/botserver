#include "start_messaging_dialog.h"

StartMessagingDialog::StartMessagingDialog() = default;

StartMessagingDialog::StartMessagingDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

StartMessagingDialog::StartMessagingDialog(const StartMessagingDialog &o) = default;

StartMessagingDialog::~StartMessagingDialog() = default;

spBotResponse StartMessagingDialog::HandleMessage(botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("StartMessagingDialog::HandleMessage");

  ButtonsType &btns = getButtons();

  return BotResponse::makeResponse(
    getMessage(),
    btns
  );
}
