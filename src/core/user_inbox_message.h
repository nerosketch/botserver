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
  UserInboxMessage(const nlohmann::json& json_dialog);
  UserInboxMessage(const UserInboxMessage &);
  virtual ~UserInboxMessage();

  inline const string &getUname() const
  {
    return uname;
  }

  inline void setUname(const string &uname)
  {
    this->uname = uname;
  }

  inline const string &getText() const
  {
    return text;
  }
  inline void setText(const string &text)
  {
    this->text = text;
  }

  inline const string& getCommand() const
  {
    return command;
  }
  inline void setCommand(const string& cmd)
  {
    command = cmd;
  }

  static spUserInboxMessage parseFromString(const string &data);

private:
  string uname;
  string text;
  string command;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserInboxMessage, uname, text, command)
};

#endif /* UserInboxMessage_H */
