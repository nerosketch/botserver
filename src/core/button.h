#ifndef Button_H
#define Button_H

#include <string>
#include <ostream>
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

  const string& GetTitle() const
  {
    return title;
  }

  void SetTitle(const string& title)
  {
    this->title = title;
  }

  const string& GetNext_dialog_name() const
  {
    return next_dialog_name;
  }

  void SetNext_dialog_name(const string& next_dialog_name)
  {
    this->next_dialog_name = next_dialog_name;
  }

  friend ostream& operator<<(ostream& os, const Button& me)
  {
    os << me.title << " " << me.next_dialog_name;
    return os;
  }

private:
  string title;
  string next_dialog_name;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Button, title, next_dialog_name)
};

#endif /* Button_H */
