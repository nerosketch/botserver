#ifndef BotResponse_H
#define BotResponse_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "preprocessors.h"
#include "button.h"

using namespace std;
using nlohmann::json;

DECLARE_SMART(BotResponse, spBotResponse);

class BotResponse
{
public:
  BotResponse();
  BotResponse(const string& text);
  BotResponse(const string& text, const vector<Button>& buttons );
  BotResponse(const BotResponse &);
  virtual ~BotResponse();

  string GetText() const
  {
    return text;
  }

  void SetText(string text)
  {
    this->text = text;
  }

  const vector<Button>& GetButtons() const
  {
    return buttons;
  }

  void SetButtons(const vector<Button>& buttons)
  {
    this->buttons = buttons;
  }

  string getJsonString();

protected:
  string text;
  vector<Button> buttons;

private:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BotResponse, text, buttons)
};

#endif /* BotResponse_H */
