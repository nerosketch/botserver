#ifndef BaseMessageInterface_H
#define BaseMessageInterface_H


#include "preprocessors.h"
#include "errors.h"
#include "user_inbox_message.h"
// #include <string>

// using namespace std;


DECLARE_SMART(BaseMessageInterface, spBaseMessageInterface);

class BaseMessageInterface {
public:

    virtual spErrorBase onMessageHandler(spUserInboxMessage& msg) = 0;

};

#endif /* BaseMessageInterface_H */
