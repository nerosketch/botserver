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

  static spClient createClient(const string &uname);
  static spClient createClient(const string &uname, const string &current_quest_name);

  const string& GetUsername() const
  {
    return username;
  }

  void SetUsername(const string& username)
  {
    this->username = username;
  }

  const string& GetCurrentQuestName() const
  {
    return currentQuestName;
  }

  void SetCurrentQuestName(const string& currentQuestName)
  {
    this->currentQuestName = currentQuestName;
  }

private:
  string username;
  string currentQuestName;
};

#endif /* Client_H */
