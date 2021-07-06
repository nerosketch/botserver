#ifndef InboxMessageDialog_H
#define InboxMessageDialog_H

#include <nlohmann/json.hpp>
#include <core/core.h>

DECLARE_SMART(InboxMessageDialog, spInboxMessageDialog);

class InboxMessageDialog : public botserver::BaseDialogInterface
{
public:
  InboxMessageDialog();
  InboxMessageDialog(const nlohmann::json& json_dialog);
  InboxMessageDialog(const InboxMessageDialog &);
  virtual ~InboxMessageDialog();

  botserver::spBotResponse handleMessage(botserver::spRequest &request) override;

};

#endif /* InboxMessageDialog_H */
