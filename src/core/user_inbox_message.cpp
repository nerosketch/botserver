#include "user_inbox_message.h"

UserInboxMessage::UserInboxMessage() = default;

UserInboxMessage::UserInboxMessage(const string& uname)
:uname(uname) {}

UserInboxMessage::UserInboxMessage(const string& uname, const string& text)
:uname(uname), text(text) {}

UserInboxMessage::UserInboxMessage(const UserInboxMessage &o) = default;

UserInboxMessage::~UserInboxMessage() = default;
