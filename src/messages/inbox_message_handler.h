#ifndef InboxMessageHandler_H
#define InboxMessageHandler_H

#include "../core/preprocessors.h"
#include "../core/base_message.h"
// #include <string>

using namespace std;

DECLARE_SMART(InboxMessageHandler, spInboxMessageHandler);

class InboxMessageHandler : public BaseMessageInterface
{
public:
    InboxMessageHandler();
    InboxMessageHandler(const InboxMessageHandler &);
    virtual ~InboxMessageHandler();

    spBotResponse onMessageHandler(const char* data) override;

private:
};

#endif /* InboxMessageHandler_H */
