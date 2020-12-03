#ifndef InboxMessageDialog_H
#define InboxMessageDialog_H


#include "../core/preprocessors.h"
#include "../core/base_dialog.h"

DECLARE_SMART(InboxMessageDialog, spInboxMessageDialog);

class InboxMessageDialog : public BaseDialogInterface {
public:
  InboxMessageDialog();
  InboxMessageDialog(const InboxMessageDialog&);
  virtual ~InboxMessageDialog();

  spBotResponse HandleMessage(spClient& client, spUserInboxMessage& msg) override;
private:

};

#endif /* InboxMessageDialog_H */
