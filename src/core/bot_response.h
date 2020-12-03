#ifndef BotResponse_H
#define BotResponse_H


#include "../core/preprocessors.h"
#include "button.h"
#include <string>
#include <vector>

using namespace std;


DECLARE_SMART(BotResponse, spBotResponse);

class BotResponse {
public:
  BotResponse();
  BotResponse(const BotResponse&);
  virtual ~BotResponse();

  string Text;
	vector<Button> Buttons;

private:

};

#endif /* BotResponse_H */
