#if !defined(DIALOGS_MAP_H)
#define DIALOGS_MAP_H

#include "../core/preprocessors.h"
#include "../core/base_dialog.h"
#include <map>
#include <memory>

using namespace std;

DECLARE_SMART(BaseDialogCreatorInterface, spBaseDialogCreatorInterface);

class BaseDialogCreatorInterface
{
public:
  virtual spBaseDialogInterface createInst() = 0;
};

extern const map<const uint16_t, spBaseDialogCreatorInterface> DialogTypeMap;

// const auto er = DialogTypeMap.at(2);
// auto ts = er->createInst();
// auto nm = ts->Name;

#endif // DIALOGS_MAP_H
