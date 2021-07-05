#ifndef InboxMessageHandler_H
#define InboxMessageHandler_H

#include <string>
#include <core/preprocessors.h>
#include <core/base_message.h>

using namespace std;

DECLARE_SMART(InboxMessageHandler, spInboxMessageHandler);

class InboxMessageHandler : public BaseMessageInterface
{
public:
  // InboxMessageHandler();
  // InboxMessageHandler(const InboxMessageHandler &);
  // virtual ~InboxMessageHandler();

  spBotResponse onMessageHandler(const string &data, botserver::spRequest &request) override;

private:
};

#endif /* InboxMessageHandler_H */
