#include <iostream>
#include "show_message_dialog.h"

using namespace std;

ShowMessageDialog::ShowMessageDialog() = default;

ShowMessageDialog::ShowMessageDialog(const ShowMessageDialog &o) = default;

ShowMessageDialog::~ShowMessageDialog() = default;

spBotResponse ShowMessageDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
  cout << "ShowMessageDialog::HandleMessage" << endl;

  return make_shared<BotResponse>("show msg dialog response");
}
