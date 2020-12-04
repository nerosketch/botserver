#ifndef UnexpectedDialog_H
#define UnexpectedDialog_H


#include "../core/preprocessors.h"
#include "../core/base_dialog.h"
#include <string>

using namespace std;


DECLARE_SMART(UnexpectedDialog, spUnexpectedDialog);

class UnexpectedDialog : public BaseDialogInterface {
public:
  UnexpectedDialog();
  UnexpectedDialog(const UnexpectedDialog&);
  virtual ~UnexpectedDialog();

  spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) override;
private:

};

#endif /* UnexpectedDialog_H */
