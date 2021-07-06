#include "start_messaging_dialog.h"

using namespace botserver;


StartMessagingDialog::StartMessagingDialog() = default;

StartMessagingDialog::StartMessagingDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

StartMessagingDialog::StartMessagingDialog(const StartMessagingDialog &o) = default;

StartMessagingDialog::~StartMessagingDialog() = default;

spBotResponse StartMessagingDialog::handleMessage(spRequest &request)
{
  DEBUG_STRUCT_LOG("StartMessagingDialog::handleMessage");

  ButtonsType &btns = getButtons();

  return BotResponse::makeResponse(
    getMessage(),
    btns
  );
}
