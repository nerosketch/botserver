#ifndef BotResponse_H
#define BotResponse_H

#include <string>
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
  BotResponse(const string& text, const ButtonsType& buttons );
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

  const ButtonsType& GetButtons() const
  {
    return buttons;
  }

  void SetButtons(const ButtonsType& buttons)
  {
    this->buttons = buttons;
  }

  string getJsonString();

  static spBotResponse makeResponse(const string& text);
  static spBotResponse makeResponse(const string& text, const ButtonsType& buttons);

protected:
  string text;
  ButtonsType buttons;

private:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BotResponse, text, buttons)
};

#endif /* BotResponse_H */
