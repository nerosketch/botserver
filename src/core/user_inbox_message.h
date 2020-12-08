#ifndef UserInboxMessage_H
#define UserInboxMessage_H

#include <string>
#include <nlohmann/json.hpp>
#include "preprocessors.h"

using namespace std;
using nlohmann::json;

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

  static spUserInboxMessage parseFromBytes(ssize_t len, const char *data);

private:
  string uname;
  string text;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserInboxMessage, uname, text)
};

#endif /* UserInboxMessage_H */
