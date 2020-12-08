#ifndef UpdateQuestHandler_H
#define UpdateQuestHandler_H

#include "../core/preprocessors.h"
#include "../core/base_message.h"

DECLARE_SMART(UpdateQuestHandler, spUpdateQuestHandler);

class UpdateQuestHandler : public BaseMessageInterface
{
public:
  UpdateQuestHandler();
  UpdateQuestHandler(const UpdateQuestHandler &);
  virtual ~UpdateQuestHandler();

  spBotResponse onMessageHandler(const char* data) override;

private:
};

#endif /* UpdateQuestHandler_H */
