#include "show_message_dialog.h"

using namespace botserver;



ShowMessageDialog::ShowMessageDialog() = default;

ShowMessageDialog::ShowMessageDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

ShowMessageDialog::ShowMessageDialog(const ShowMessageDialog &o) = default;

ShowMessageDialog::~ShowMessageDialog() = default;

spBotResponse ShowMessageDialog::handleMessage(spRequest &request)
{
  DEBUG_STRUCT_LOG("ShowMessageDialog::handleMessage");

  return BotResponse::makeResponse(getMessage());
}
