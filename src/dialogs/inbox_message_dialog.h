#ifndef InboxMessageDialog_H
#define InboxMessageDialog_H

#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/base_dialog.h>
#include <core/request.h>

DECLARE_SMART(InboxMessageDialog, spInboxMessageDialog);

class InboxMessageDialog : public BaseDialogInterface
{
public:
  InboxMessageDialog();
  InboxMessageDialog(const nlohmann::json& json_dialog);
  InboxMessageDialog(const InboxMessageDialog &);
  virtual ~InboxMessageDialog();

  spBotResponse HandleMessage(spRequest &request) const override;

private:
};

#endif /* InboxMessageDialog_H */
