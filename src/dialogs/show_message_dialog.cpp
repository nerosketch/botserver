#include "show_message_dialog.h"

ShowMessageDialog::ShowMessageDialog() = default;

ShowMessageDialog::ShowMessageDialog(const nlohmann::json& json_dialog):
BaseDialogInterface(json_dialog) {}

ShowMessageDialog::ShowMessageDialog(const ShowMessageDialog &o) = default;

ShowMessageDialog::~ShowMessageDialog() = default;

spBotResponse ShowMessageDialog::HandleMessage(botserver::spRequest &request) const
{
  DEBUG_STRUCT_LOG("ShowMessageDialog::HandleMessage");

  return BotResponse::makeResponse(GetMessage());
}
