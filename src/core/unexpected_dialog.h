#ifndef UnexpectedDialog_H
#define UnexpectedDialog_H


#include "preprocessors.h"
#include "base_dialog.h"


DECLARE_SMART(UnexpectedDialog, spUnexpectedDialog);

class UnexpectedDialog : public BaseDialogInterface {
public:
  
  static UnexpectedDialog& getInstance()
  {
    static UnexpectedDialog singletone;
    return singletone;
  }

  spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) override;

private:
  UnexpectedDialog();
  UnexpectedDialog(const UnexpectedDialog&);
  virtual ~UnexpectedDialog();
  UnexpectedDialog &operator=(const UnexpectedDialog&);
};

#endif /* UnexpectedDialog_H */
