#ifndef BotResponse_H
#define BotResponse_H

#include <string>
#include <vector>
#include "preprocessors.h"
#include "button.h"

using namespace std;

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
    text = text;
  }

  vector<Button> GetButtons() const
  {
    return buttons;
  }

  void SetButtons(vector<Button> buttons)
  {
    buttons = buttons;
  }

protected:
  string text;
  vector<Button> buttons;
};

#endif /* BotResponse_H */
