#ifndef Client_H
#define Client_H

#include <string>
#include "preprocessors.h"
#include "base_dialog.h"

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

  inline const string& getUsername() const
  {
    return username;
  }

  inline void setUsername(const string& username)
  {
    this->username = username;
  }

  inline const string& getCurrentQuestName() const
  {
    return currentQuestName;
  }

  inline void setCurrentQuestName(const string& current_quest_name)
  {
    currentQuestName = current_quest_name;
  }

  inline const spBaseDialogInterface& getCurrentDialog() const
  {
    return current_dialog;
  }

  inline void setCurrentDialog(const spBaseDialogInterface &dialog)
  {
    current_dialog = dialog;
  }

private:
  string username;
  string currentQuestName;
  spBaseDialogInterface current_dialog;
};

#endif /* Client_H */
