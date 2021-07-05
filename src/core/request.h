#ifndef Request_H
#define Request_H


#include "preprocessors.h"
#include <string>
#include "client.h"
#include "user_inbox_message.h"

using namespace std;


DECLARE_SMART(Request, spRequest);

class Request {
public:
  Request();
  Request(const Request&);
  virtual ~Request();

  inline spClient& getClient()
  {
    return client;
  }
  inline void setClient(spClient &client)
  {
    this->client = client;
  }

  inline spUserInboxMessage& getUserInboxMessage()
  {
    return message;
  }
  inline void setMessage(spUserInboxMessage &message)
  {
    this->message = message;
  }

private:
  spClient client;
  spUserInboxMessage message;
};

#endif /* Request_H */
