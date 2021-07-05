#ifndef StartMessagingDialog_H
#define StartMessagingDialog_H

#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/base_dialog.h>
#include <core/request.h>

DECLARE_SMART(StartMessagingDialog, spStartMessagingDialog);

typedef std::vector<Button> ButtonsType;

class StartMessagingDialog : public BaseDialogInterface
{
public:
  StartMessagingDialog();
  StartMessagingDialog(const nlohmann::json& json_dialog);
  StartMessagingDialog(const StartMessagingDialog &);
  virtual ~StartMessagingDialog();

  spBotResponse HandleMessage(spRequest &request) const override;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(StartMessagingDialog, buttons)

private:
  ButtonsType buttons;
};

#endif /* StartMessagingDialog_H */
