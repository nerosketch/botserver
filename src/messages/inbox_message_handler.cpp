#include "inbox_message_handler.h"

// InboxMessageHandler ::InboxMessageHandler() = default;

// InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

// InboxMessageHandler ::~InboxMessageHandler() = default;


spBotResponse _inbox_client_msg(botserver::spRequest &request)
{
  auto c = request->getClient();

  const spQuest& current_quest = c->getCurrentQuest(); 
  if (!current_quest)
  {
    const QuestStorage& qs = QuestStorage::getInstance();
    const spQuest &quest = qs.getDefaultQuest();
    request->setCurrentQuest(quest);
    return quest->handleMessage(request);
  }

  request->setCurrentQuest(current_quest);

  return current_quest->handleMessage(request);
}


spBotResponse InboxMessageHandler::onMessageHandler(const string &data, botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("Message type 1, onInboxMessageHandler()");

  spUserInboxMessage msg = UserInboxMessage::parseFromString(data);
  if (!msg)
  {
    return nullptr;
  }

  const string& uname = msg->getUname();
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
    auto new_client = Client::createClient(uname, quest);
    request->setClient(new_client);
    cs.AddClient(new_client);
    return _inbox_client_msg(request);
  }

  return BotResponse::makeResponse("InboxMessageHandler message");
}
