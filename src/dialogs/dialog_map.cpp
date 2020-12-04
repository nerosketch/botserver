#include "dialog_map.h"

#include "start_messaging_dialog.h"
#include "inbox_message_dialog.h"
#include "show_message_dialog.h"

using namespace std;

template<typename T>
class DialogInstanceCreatorTemplate : public BaseDialogCreatorInterface {
public:
  spBaseDialogInterface createInst() {
    return make_shared<T>();
  }
};

#define DAT_TYPE(number, class_name) \
    { number, make_shared<DialogInstanceCreatorTemplate<class_name>>() }



const map<const uint16_t, shared_ptr<BaseDialogCreatorInterface>> DialogTypeMap = {
  DAT_TYPE(1, StartMessagingDialog),
  DAT_TYPE(2, InboxMessageDialog),
  DAT_TYPE(3, ShowMessageDialog)
};
