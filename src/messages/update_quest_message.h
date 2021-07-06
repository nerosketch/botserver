#ifndef UpdateQuestHandler_H
#define UpdateQuestHandler_H

#include <string>
#include <core/core.h>

DECLARE_SMART(UpdateQuestHandler, spUpdateQuestHandler);

class UpdateQuestHandler : public botserver::BaseMessageInterface
{
public:
  UpdateQuestHandler();
  UpdateQuestHandler(const UpdateQuestHandler &);
  virtual ~UpdateQuestHandler();

  botserver::spBotResponse onMessageHandler(const std::string &data, botserver::spRequest &request) override;

private:
};

#endif /* UpdateQuestHandler_H */
