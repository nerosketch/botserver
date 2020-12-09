#include "inbox_message_handler.h"
#include "../core/user_inbox_message.h"
#include "../core/client_storage.h"
#include "../core/quest_storage.h"

// InboxMessageHandler ::InboxMessageHandler() = default;

// InboxMessageHandler ::InboxMessageHandler(const InboxMessageHandler &o) = default;

// InboxMessageHandler ::~InboxMessageHandler() = default;


spBotResponse _inbox_client_msg(spClient& c, spUserInboxMessage& msg)
{
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

  return quest->HandleMessage(c, msg);
}


spBotResponse InboxMessageHandler::onMessageHandler(ssize_t len, const char* data)
{
  DEBUG_STRUCT_LOG("Message type 1, onInboxMessageHandler()");

  spUserInboxMessage msg = UserInboxMessage::parseFromBytes(len, data);
  const string& uname = msg->GetUname();
  if (uname.empty())
  {
    return BotResponse::makeResponse("uname not found in data");
  }

  ClientStorage& cs = ClientStorage::getInstance();
  spClient client = cs.FindClient(uname);
  if (client)
  {
    return _inbox_client_msg(client, msg);
  }
  else 
  {
    // Get default quest
    const QuestStorage& qs = QuestStorage::getInstance();
    auto quest = qs.getDefaultQuest();

    // Create new client
    auto new_client = Client::createClient(uname, quest->GetTitle());
    cs.AddClient(new_client);
    return _inbox_client_msg(new_client, msg);
  }


  return BotResponse::makeResponse("InboxMessageHandler message");
}
