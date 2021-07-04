#include <iostream>
#include "user_inbox_message.h"

UserInboxMessage::UserInboxMessage() = default;

UserInboxMessage::UserInboxMessage(const string &uname)
    : uname(uname) {}

UserInboxMessage::UserInboxMessage(const string &uname, const string &text)
    : uname(uname), text(text) {}

UserInboxMessage::UserInboxMessage(const UserInboxMessage &o) = default;

UserInboxMessage::~UserInboxMessage() = default;

spUserInboxMessage UserInboxMessage::parseFromString(const string &data)
{
  json j;
  try
  {
    j = json::parse(data);
  }
  catch (json::parse_error &ex)
  {
    cerr << "ERROR: parse error at byte " << ex.byte << endl;
    return nullptr;
  }
  auto parsed_inbox_message = j.get<UserInboxMessage>();

  auto sp_inbox_msg = make_shared<UserInboxMessage>();
  *sp_inbox_msg = parsed_inbox_message;
  return sp_inbox_msg;
}
