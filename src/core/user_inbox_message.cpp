#include <iostream>
#include "user_inbox_message.h"

UserInboxMessage::UserInboxMessage() = default;

UserInboxMessage::UserInboxMessage(const string &uname)
    : uname(uname) {}

UserInboxMessage::UserInboxMessage(const string &uname, const string &text)
    : uname(uname), text(text) {}

UserInboxMessage::UserInboxMessage(const UserInboxMessage &o) = default;

UserInboxMessage::~UserInboxMessage() = default;

spUserInboxMessage UserInboxMessage::parseFromBytes(ssize_t len, const char *data)
{
  json j;
  try
  {
    j = json::parse(data);
  }
  catch (json::parse_error &ex)
  {
    cerr << "parse error at byte " << ex.byte << endl;
  }
  доделать
}
