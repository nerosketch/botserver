#include "base_dialog.h"

BaseDialogInterface::BaseDialogInterface() = default;

BaseDialogInterface::BaseDialogInterface(const nlohmann::json& json_dialog):
name(json_dialog.value("name", "")),
dialogType(json_dialog.value("dialog_type", 0)),
message(json_dialog.value("message", ""))
{}

BaseDialogInterface::BaseDialogInterface(const BaseDialogInterface &) = default;

BaseDialogInterface::~BaseDialogInterface() = default;
