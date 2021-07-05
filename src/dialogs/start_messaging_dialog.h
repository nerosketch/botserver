#ifndef StartMessagingDialog_H
#define StartMessagingDialog_H

#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/base_dialog.h>
#include <core/request.h>
#include <core/button.h>

DECLARE_SMART(StartMessagingDialog, spStartMessagingDialog);

class StartMessagingDialog : public BaseDialogInterface
{
public:
  StartMessagingDialog();
  StartMessagingDialog(const nlohmann::json& json_dialog);
  StartMessagingDialog(const StartMessagingDialog &);
  virtual ~StartMessagingDialog();

  spBotResponse HandleMessage(botserver::spRequest &request) override;
};

#endif /* StartMessagingDialog_H */
