#ifndef UnexpectedDialog_H
#define UnexpectedDialog_H

#include "preprocessors.h"
#include "base_dialog.h"
#include "request.h"

DECLARE_SMART(UnexpectedDialog, spUnexpectedDialog);

class UnexpectedDialog : public BaseDialogInterface
{
public:
  inline static UnexpectedDialog& getInstance()
  {
    static UnexpectedDialog singletone;
    return singletone;
  }

  spBotResponse HandleMessage(botserver::spRequest &request) override;

private:
  UnexpectedDialog();
  UnexpectedDialog(const UnexpectedDialog &);
  virtual ~UnexpectedDialog();
  UnexpectedDialog &operator=(const UnexpectedDialog &);
};

#endif /* UnexpectedDialog_H */
