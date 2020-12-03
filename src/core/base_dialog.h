#ifndef BaseDialogInterface_H
#define BaseDialogInterface_H

#include <string>
#include "preprocessors.h"
#include "bot_response.h"
#include "client.h"
#include "user_inbox_message.h"

using namespace std;

DECLARE_SMART(BaseDialogInterface, spBaseDialogInterface);

class BaseDialogInterface
{
public:
  BaseDialogInterface();
  BaseDialogInterface(const BaseDialogInterface &);
  virtual ~BaseDialogInterface();

  string GetName() const
  {
    return name;
  }

  void SetName(string name)
  {
    name = name;
  }

  uint16_t GetDialogType() const
  {
    return dialogType;
  }

  void SetDialogType(uint16_t dialogType)
  {
    dialogType = dialogType;
  }

  string GetMessage() const
  {
    return message;
  }

  void SetMessage(string message)
  {
    message = message;
  }

  virtual spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) = 0;

private:
  string name;
  uint16_t dialogType;
  string message;

};

#endif /* BaseDialogInterface_H */
