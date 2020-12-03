#ifndef BaseDialogInterface_H
#define BaseDialogInterface_H

#include <string>
#include "preprocessors.h"
#include "bot_response.h"
#include "client.h"
#include "user_inbox_message.h"

using namespace std;

DECLARE_SMART(BaseDialogInterface, spBaseDialogInterface);

class BaseDialogInterface {
public:
  BaseDialogInterface();
  BaseDialogInterface(const BaseDialogInterface&);
  virtual ~BaseDialogInterface();

  string name;
	uint16_t dialogType;
  string message;

  virtual spBotResponse HandleMessage(spClient& client, spUserInboxMessage& msg) = 0;

private:

};

#endif /* BaseDialogInterface_H */
