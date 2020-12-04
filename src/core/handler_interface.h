#ifndef HandlerInterface_H
#define HandlerInterface_H


#include "preprocessors.h"
#include "bot_response.h"
#include "client.h"
#include "user_inbox_message.h"

DECLARE_SMART(HandlerInterface, spHandlerInterface);

class HandlerInterface {
public:
    virtual spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) = 0;

};

#endif /* HandlerInterface_H */
