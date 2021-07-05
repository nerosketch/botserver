#ifndef ShowMessageDialog_H
#define ShowMessageDialog_H

#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/base_dialog.h>
#include <core/request.h>

DECLARE_SMART(ShowMessageDialog, spShowMessageDialog);

class ShowMessageDialog : public BaseDialogInterface
{
public:
  ShowMessageDialog();
  ShowMessageDialog(const nlohmann::json& json_dialog);
  ShowMessageDialog(const ShowMessageDialog &);
  virtual ~ShowMessageDialog();

  spBotResponse HandleMessage(botserver::spRequest &request) const override;

private:
};

#endif /* ShowMessageDialog_H */
