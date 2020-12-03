#ifndef UserInboxMessage_H
#define UserInboxMessage_H

#include "../core/preprocessors.h"
#include <string>

using namespace std;

DECLARE_SMART(UserInboxMessage, spUserInboxMessage);

class UserInboxMessage
{
public:
  UserInboxMessage();
  UserInboxMessage(const UserInboxMessage &);
  virtual ~UserInboxMessage();

private:
};

#endif /* UserInboxMessage_H */
