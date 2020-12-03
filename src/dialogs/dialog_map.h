#if !defined(DIALOGS_MAP_H)
#define DIALOGS_MAP_H

#include "../core/base_dialog.h"
#include <map>
#include <memory>

class BaseCreatorInterface
{
public:
  virtual spBaseDialogInterface createInst() = 0;
};

extern const std::map<const uint16_t, std::shared_ptr<BaseCreatorInterface>> DialogTypeMap;

// const auto er = DialogTypeMap.at(2);
// auto ts = er->createInst();
// auto nm = ts->Name;

#endif // DIALOGS_MAP_H
