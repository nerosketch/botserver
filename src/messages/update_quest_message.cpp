#include <iostream>
#include <map>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "update_quest_message.h"
#include <core/button.h>
#include <core/quest.h>
#include <core/quest_storage.h>
#include <dialogs/dialog_map.h>

using namespace std;
using nlohmann::json;

DECLARE_SMART(DialogStructClass, spDialogStructClass);
class DialogStructClass
{
public:
  // DialogStructClass();
  // DialogStructClass(const DialogStructClass&);
  // virtual ~DialogStructClass();
private:
  string name;
  uint16_t dialog_type;
  string message;
  vector<Button> buttons;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(DialogStructClass, name, dialog_type, message, buttons)
};

DECLARE_SMART(QuestStructClass, spQuestStructClass);
class QuestStructClass
{
public:
  // QuestStructClass();
  // QuestStructClass(const QuestStructClass&);
  // virtual ~QuestStructClass();
private:
  string title;
  string description;
  string first_dialog;
  map<string, DialogStructClass> dialogs;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(QuestStructClass, title, description, first_dialog)
};

UpdateQuestHandler::UpdateQuestHandler() = default;

UpdateQuestHandler::UpdateQuestHandler(const UpdateQuestHandler &o) = default;

UpdateQuestHandler::~UpdateQuestHandler() = default;

spBotResponse UpdateQuestHandler::onMessageHandler(const string &data, botserver::spRequest &request)
{
  DEBUG_STRUCT_LOG("Message type 3, onUpdateQuestHandler()");

  json j;
  try
  {
    j = json::parse(data);
  }
  catch (json::parse_error &err)
  {
    #ifdef DEBUG
    std::cerr << "parse error at byte " << err.byte << std::endl;
    #endif

    return BotResponse::makeResponse(err.what());
  }

  QuestMapType quests_map;

  for (const auto &q : j)
  {
    auto quest = Quest::makeQuest(
        q.value("title", "default title"),
        q.value("description", "default description"),
        q.value("first_dialog", "start"));
    const auto &q_dialogs = q["dialogs"];

    unordered_map<string, spBaseDialogInterface> dialogs;
    dialogs.reserve(q_dialogs.size());
    for (const auto &q_dialog : q_dialogs)
    {
      uint16_t q_dialog_type = q_dialog.value("dialog_type", 0);

      const auto &type_el = DialogTypeMap.find(q_dialog_type);
      if (type_el != DialogTypeMap.end())
      {
        // Found dialog creator by dialog type integer
        const auto &dialog_creator = type_el->second;
        auto dialog_instance = dialog_creator->createInst(q_dialog); 

        try
        {
          const auto &q_dialog_name = q_dialog.at("name");

          dialogs[q_dialog_name] = dialog_instance;
        }
        catch (json::out_of_range &err)
        {
          std::cerr << "parse error, dialog has no name: " << err.what() << std::endl;
          return nullptr;
        }
      }
    }
    quest->setDialogs(dialogs);
    quests_map[quest->GetTitle()] = quest;
  }

  auto& qs = QuestStorage::getInstance();
  qs.setQuests(quests_map);

  return BotResponse::makeResponse("UpdateQuestHandler message ok");
}
