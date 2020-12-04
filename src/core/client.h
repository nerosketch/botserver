#ifndef Client_H
#define Client_H

#include <string>
#include "preprocessors.h"

using namespace std;

DECLARE_SMART(Client, spClient);

class Client
{
public:
  Client();
  Client(const string &uname);
  Client(const string &uname, const string &current_quest_name);
  Client(const Client &);
  virtual ~Client();

  string GetUsername() const
  {
    return username;
  }

  void SetUsername(string username)
  {
    username = username;
  }

  string GetCurrentQuestName() const
  {
    return currentQuestName;
  }

  void SetCurrentQuestName(string currentQuestName)
  {
    currentQuestName = currentQuestName;
  }

private:
  string username;
  string currentQuestName;
};

#endif /* Client_H */
