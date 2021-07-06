#ifndef StartMessagingDialog_H
#define StartMessagingDialog_H

#include <nlohmann/json.hpp>
#include <core/core.h>

DECLARE_SMART(StartMessagingDialog, spStartMessagingDialog);

class StartMessagingDialog : public botserver::BaseDialogInterface
{
public:
  StartMessagingDialog();
  StartMessagingDialog(const nlohmann::json& json_dialog);
  StartMessagingDialog(const StartMessagingDialog &);
  virtual ~StartMessagingDialog();

  botserver::spBotResponse handleMessage(botserver::spRequest &request) override;
};

#endif /* StartMessagingDialog_H */
