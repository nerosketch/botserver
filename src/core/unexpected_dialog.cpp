
#include "unexpected_dialog.h"

UnexpectedDialog::UnexpectedDialog() = default;

UnexpectedDialog::UnexpectedDialog(const UnexpectedDialog &o) = default;

UnexpectedDialog::~UnexpectedDialog() = default;

spBotResponse UnexpectedDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
    DEBUG_STRUCT_LOG("UnexpectedDialog::HandleMessage");

    return BotResponse::makeResponse("Не понимаю о чём речь");
}
