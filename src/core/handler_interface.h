#ifndef HandlerInterface_H
#define HandlerInterface_H


#include "preprocessors.h"
#include "request.h"

DECLARE_SMART(HandlerInterface, spHandlerInterface);

class HandlerInterface {
public:
  virtual spBotResponse HandleMessage(botserver::spRequest &request) const = 0;

};

#endif /* HandlerInterface_H */
