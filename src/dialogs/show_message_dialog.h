#ifndef ShowMessageDialog_H
#define ShowMessageDialog_H

#include "../core/preprocessors.h"
#include "../core/base_dialog.h"

DECLARE_SMART(ShowMessageDialog, spShowMessageDialog);

class ShowMessageDialog : public BaseDialogInterface
{
public:
  ShowMessageDialog();
  ShowMessageDialog(const ShowMessageDialog &);
  virtual ~ShowMessageDialog();

  spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) override;

private:
};

#endif /* ShowMessageDialog_H */
