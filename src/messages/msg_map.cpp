#include "msg_map.h"
#include "inbox_message_handler.h"
#include "update_quest_message.h"

template<typename T>
class MsgInstanceCreatorTemplate : public BaseMsgCreatorInterface {
public:
  spBaseMessageInterface createInst() {
    return make_shared<T>();
  }
};

#define DAT_TYPE(number, class_name) \
    { number, make_shared<MsgInstanceCreatorTemplate<class_name>>() }


const unordered_map<const uint16_t, spBaseMsgCreatorInterface> MessageTypeMap = {
  DAT_TYPE(1, InboxMessageHandler),
//   DAT_TYPE(2, InboxMessageDialog),
  DAT_TYPE(3, UpdateQuestHandler)
};
