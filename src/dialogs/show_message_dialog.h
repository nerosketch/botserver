#ifndef ShowMessageDialog_H
#define ShowMessageDialog_H

#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/core.h>

DECLARE_SMART(ShowMessageDialog, spShowMessageDialog);

class ShowMessageDialog : public botserver::BaseDialogInterface
{
public:
  ShowMessageDialog();
  ShowMessageDialog(const nlohmann::json& json_dialog);
  ShowMessageDialog(const ShowMessageDialog &);
  virtual ~ShowMessageDialog();

  botserver::spBotResponse handleMessage(botserver::spRequest &request) override;

};

#endif /* ShowMessageDialog_H */
