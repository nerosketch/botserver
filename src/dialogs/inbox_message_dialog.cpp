#include <iostream>
#include "inbox_message_dialog.h"

using namespace std;

InboxMessageDialog::InboxMessageDialog() = default;

InboxMessageDialog::InboxMessageDialog(const InboxMessageDialog &o) = default;

InboxMessageDialog::~InboxMessageDialog() = default;

spBotResponse InboxMessageDialog::HandleMessage(spClient &client, spUserInboxMessage &msg)
{
  cout << "InboxMessageDialog::HandleMessage" << endl;

  return make_shared<BotResponse>("Inbox msg dialog response");
}
