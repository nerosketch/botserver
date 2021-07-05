#include "base_dialog.h"

BaseDialogInterface::BaseDialogInterface() = default;

BaseDialogInterface::BaseDialogInterface(const nlohmann::json& json_dialog)
{
  from_json(json_dialog, *this);
}

BaseDialogInterface::BaseDialogInterface(const BaseDialogInterface &) = default;

BaseDialogInterface::~BaseDialogInterface() = default;
