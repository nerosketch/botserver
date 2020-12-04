#ifndef UserInboxMessage_H
#define UserInboxMessage_H

#include "preprocessors.h"
#include <string>

using namespace std;

DECLARE_SMART(UserInboxMessage, spUserInboxMessage);

class UserInboxMessage
{
public:
  UserInboxMessage();
  UserInboxMessage(const string& uname);
  UserInboxMessage(const string& uname, const string& text);
  UserInboxMessage(const UserInboxMessage &);
  virtual ~UserInboxMessage();

  inline const string &GetUname() const
  {
    return uname;
  }

  inline void SetUname(const string &uname)
  {
    this->uname = uname;
  }

  inline const string &GetText() const
  {
    return text;
  }
  inline void SetText(const string &text)
  {
    this->text = text;
  }

private:
  string uname;
  string text;
};

#endif /* UserInboxMessage_H */
