#ifndef Request_H
#define Request_H


#include "preprocessors.h"
#include <httplib.h>
#include <string>
#include "client.h"
#include "user_inbox_message.h"

using namespace std;

namespace botserver {

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

    inline const httplib::Request *getHttpRequestPtr() const
    {
      return p_http_request;
    }
    inline void setHttpRequestPtr(const httplib::Request *p_req)
    {
      p_http_request = p_req;
    }

  private:
    spClient client;
    spUserInboxMessage message;
    const httplib::Request *p_http_request;
  };
}

#endif /* Request_H */
