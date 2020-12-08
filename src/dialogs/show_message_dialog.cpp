#include "show_message_dialog.h"

ShowMessageDialog::ShowMessageDialog() = default;

ShowMessageDialog::ShowMessageDialog(const ShowMessageDialog &o) = default;

ShowMessageDialog::~ShowMessageDialog() = default;

spBotResponse ShowMessageDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
  DEBUG_STRUCT_LOG("ShowMessageDialog::HandleMessage");

  return BotResponse::makeResponse("show msg dialog response");
}
