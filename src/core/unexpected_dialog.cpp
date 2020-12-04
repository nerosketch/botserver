
#include "unexpected_dialog.h"
#include <iostream>

using namespace std;

UnexpectedDialog::UnexpectedDialog() = default;

UnexpectedDialog::UnexpectedDialog(const UnexpectedDialog &o) = default;

UnexpectedDialog::~UnexpectedDialog() = default;

spBotResponse UnexpectedDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
    cout << "UnexpectedDialog::HandleMessage" << endl;
    return make_shared<BotResponse>("Не понимаю о чём речь");
}
