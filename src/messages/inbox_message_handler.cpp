#include "inbox_message_handler.h"
#include <core/user_inbox_message.h>
#include <core/client_storage.h>
#include <core/quest_storage.h>

// InboxMessageHandler ::InboxMessageHandler() = default;

// InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

// InboxMessageHandler ::~InboxMessageHandler() = default;


spBotResponse _inbox_client_msg(botserver::spRequest &request)
{
  auto c = request->getClient();

  const string& current_quest_name = c->GetCurrentQuestName();
  if (current_quest_name.empty())
  {
    return BotResponse::makeResponse("current_quest_name is empty");
  }

  const QuestStorage& qs = QuestStorage::getInstance();
  spQuest quest = qs.findQuest(current_quest_name);
  if (!quest)
  {
    return BotResponse::makeResponse("Current quest not found");
  }

  request->setCurrentQuest(quest);

  return quest->HandleMessage(request);
}


spBotResponse InboxMessageHandler::onMessageHandler(const string &data, botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("Message type 1, onInboxMessageHandler()");

  spUserInboxMessage msg = UserInboxMessage::parseFromString(data);
  if (!msg)
  {
    return nullptr;
  }

  const string& uname = msg->GetUname();
  if (uname.empty())
  {
    return BotResponse::makeResponse("uname not found in data");
  }

  ClientStorage& cs = ClientStorage::getInstance();
  spClient client = cs.FindClient(uname);

  request->setMessage(msg);

  if (client)
  {
    request->setClient(client);
    return _inbox_client_msg(request);
  }
  else
  {
    // Get default quest
    const QuestStorage& qs = QuestStorage::getInstance();
    auto quest = qs.getDefaultQuest();

    // Create new client
    auto new_client = Client::createClient(uname, quest->GetTitle());
    request->setClient(new_client);
    request->setCurrentQuest(quest);
    cs.AddClient(new_client);
    return _inbox_client_msg(request);
  }

  return BotResponse::makeResponse("InboxMessageHandler message");
}
