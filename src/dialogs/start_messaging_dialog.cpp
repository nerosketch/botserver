#include <iostream>
#include "start_messaging_dialog.h"

using namespace std;

StartMessagingDialog::StartMessagingDialog() = default;

StartMessagingDialog::StartMessagingDialog(const StartMessagingDialog &o) = default;

StartMessagingDialog::~StartMessagingDialog() = default;

spBotResponse StartMessagingDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
  cout << "StartMessagingDialog::HandleMessage" << endl;

  return make_shared<BotResponse>("start msg dialog response");
}
