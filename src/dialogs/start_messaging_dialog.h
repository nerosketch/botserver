#ifndef StartMessagingDialog_H
#define StartMessagingDialog_H

#include <nlohmann/json.hpp>
#include "../core/preprocessors.h"
#include "../core/base_dialog.h"

DECLARE_SMART(StartMessagingDialog, spStartMessagingDialog);

class StartMessagingDialog : public BaseDialogInterface
{
public:
  StartMessagingDialog();
  StartMessagingDialog(const nlohmann::json& json_dialog);
  StartMessagingDialog(const StartMessagingDialog &);
  virtual ~StartMessagingDialog();

  spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) const override;

private:
};

#endif /* StartMessagingDialog_H */
