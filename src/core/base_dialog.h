#ifndef BaseDialogInterface_H
#define BaseDialogInterface_H

#include <string>
#include <nlohmann/json.hpp>
#include "preprocessors.h"
#include "handler_interface.h"
#include "button.h"

using namespace std;

DECLARE_SMART(BaseDialogInterface, spBaseDialogInterface);

class BaseDialogInterface : public HandlerInterface
{
public:
  BaseDialogInterface();
  BaseDialogInterface(const nlohmann::json& json_dialog);
  BaseDialogInterface(const BaseDialogInterface &);
  virtual ~BaseDialogInterface();

  const string& GetName() const
  {
    return name;
  }

  inline void SetName(const string& name)
  {
    this->name = name;
  }

  inline uint16_t getDialogType() const
  {
    return dialog_type;
  }

  inline void setDialogType(uint16_t dialogType)
  {
    this->dialog_type = dialogType;
  }

  inline const string& getMessage() const
  {
    return message;
  }

  inline void setMessage(const string& message)
  {
    this->message = message;
  }

  inline ButtonsType& getButtons()
  {
    return buttons;
  }

  inline void setButtons(const ButtonsType &btns)
  {
    buttons = btns;
  }

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BaseDialogInterface, name, dialog_type, message, buttons)

private:
  string name;
  uint16_t dialog_type;
  string message;
  ButtonsType buttons;
};

#endif /* BaseDialogInterface_H */
