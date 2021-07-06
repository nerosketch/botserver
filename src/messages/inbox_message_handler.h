#ifndef InboxMessageHandler_H
#define InboxMessageHandler_H

#include <string>
#include <core/core.h>

using namespace std;
using namespace botserver;

DECLARE_SMART(InboxMessageHandler, spInboxMessageHandler);

class InboxMessageHandler : public BaseMessageInterface
{
public:
  // InboxMessageHandler();
  // InboxMessageHandler(const InboxMessageHandler &);
  // virtual ~InboxMessageHandler();

  spBotResponse onMessageHandler(const string &data, spRequest &request) override;

private:
};

#endif /* InboxMessageHandler_H */
