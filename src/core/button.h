#ifndef Button_H
#define Button_H

#include <string>
#include <ostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "preprocessors.h"

DECLARE_SMART(Button, spButton);

using namespace std;
using nlohmann::json;

class Button
{
public:
  Button();
  Button(const Button &);
  virtual ~Button();

  inline const string& GetTitle() const
  {
    return title;
  }

  inline void setTitle(const string& title)
  {
    this->title = title;
  }

  inline const string& getNextDialogName() const
  {
    return next_dialog_name;
  }

  inline void setNextDialogName(const string& next_dialog_name)
  {
    this->next_dialog_name = next_dialog_name;
  }

  friend ostream& operator<<(ostream& os, const Button& me)
  {
    os << me.title << " " << me.next_dialog_name;
    return os;
  }

  inline const string& getCommand() const
  {
    return command;
  }

  inline void setCommand(const string &cmd)
  {
    command = cmd;
  }

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Button, title, next_dialog_name, command)

private:
  string title;
  string next_dialog_name;
  string command;
};

typedef vector<Button> ButtonsType;

#endif /* Button_H */
