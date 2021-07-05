#ifndef BaseMessageInterface_H
#define BaseMessageInterface_H


#include "preprocessors.h"
#include "bot_response.h"
#include "request.h"
#include <string>


DECLARE_SMART(BaseMessageInterface, spBaseMessageInterface);

class BaseMessageInterface {
public:

  virtual spBotResponse onMessageHandler(const std::string &data, botserver::spRequest &request) = 0;

};

#endif /* BaseMessageInterface_H */
