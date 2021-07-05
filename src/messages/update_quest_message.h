#ifndef UpdateQuestHandler_H
#define UpdateQuestHandler_H

#include <string>
#include <core/preprocessors.h>
#include <core/base_message.h>

DECLARE_SMART(UpdateQuestHandler, spUpdateQuestHandler);

class UpdateQuestHandler : public BaseMessageInterface
{
public:
  UpdateQuestHandler();
  UpdateQuestHandler(const UpdateQuestHandler &);
  virtual ~UpdateQuestHandler();

  spBotResponse onMessageHandler(const std::string &data, botserver::spRequest &request) override;

private:
};

#endif /* UpdateQuestHandler_H */
