#include <iostream>
#include "update_quest_message.h"

using namespace std;

UpdateQuestHandler::UpdateQuestHandler() = default;

UpdateQuestHandler::UpdateQuestHandler(const UpdateQuestHandler &o) = default;

UpdateQuestHandler::~UpdateQuestHandler() = default;

spBotResponse UpdateQuestHandler::onMessageHandler(const char* data)
{
  cout << "Message type 3, onUpdateQuestHandler()" << endl;
  return make_shared<BotResponse>("UpdateQuestHandler message");
}
