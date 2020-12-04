#ifndef BaseDialogInterface_H
#define BaseDialogInterface_H

#include <string>
#include "preprocessors.h"
#include "bot_response.h"
#include "client.h"
#include "user_inbox_message.h"
#include "handler_interface.h"

using namespace std;

DECLARE_SMART(BaseDialogInterface, spBaseDialogInterface);

class BaseDialogInterface : public HandlerInterface
{
public:
  BaseDialogInterface();
  BaseDialogInterface(const BaseDialogInterface &);
  virtual ~BaseDialogInterface();

  const string& GetName() const
  {
    return name;
  }

  void SetName(const string& name)
  {
    this->name = name;
  }

  uint16_t GetDialogType() const
  {
    return dialogType;
  }

  void SetDialogType(uint16_t dialogType)
  {
    this->dialogType = dialogType;
  }

  const string& GetMessage() const
  {
    return message;
  }

  void SetMessage(const string& message)
  {
    this->message = message;
  }

private:
  string name;
  uint16_t dialogType;
  string message;

};

#endif /* BaseDialogInterface_H */
