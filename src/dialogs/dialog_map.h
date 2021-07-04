#if !defined(DIALOGS_MAP_H)
#define DIALOGS_MAP_H

#include <map>
#include <nlohmann/json.hpp>
#include <core/preprocessors.h>
#include <core/base_dialog.h>

using namespace std;

DECLARE_SMART(BaseDialogCreatorInterface, spBaseDialogCreatorInterface);

class BaseDialogCreatorInterface
{
public:
  virtual spBaseDialogInterface createInst(const nlohmann::json& json_dialog) = 0;
};

typedef map<const uint16_t, spBaseDialogCreatorInterface> DialogTypeMapType;

extern const DialogTypeMapType DialogTypeMap;

// const auto er = DialogTypeMap.at(2);
// auto ts = er->createInst();
// auto nm = ts->Name;

#endif // DIALOGS_MAP_H
