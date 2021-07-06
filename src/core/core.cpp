#include "core.h"
#include <fmt/core.h>

namespace botserver {

  // Errors
  Error::Error() = default;

  Error::Error(const string &msg, int err_code)
      : message_text(msg), error_num(err_code) {}

  Error::Error(const Error &o) = default;

  Error::~Error() = default;

  spError Error::makeError(const string &msg, int err_code)
  {
      return make_shared<Error>(msg, err_code);
  }

  void Error::sendError(spError err)
  {
    sendError(err->message_text, err->error_num);
  }

  void Error::sendError(const string &msg, int err_code)
  {
    // Temporary. TODO: Make it functionality
    std::cerr << msg << " - " << err_code << std::endl;
  }
  // End Errors






  // BaseDialoginterface
  BaseDialogInterface::BaseDialogInterface() = default;

  BaseDialogInterface::BaseDialogInterface(const nlohmann::json& json_dialog)
  {
  from_json(json_dialog, *this);
  }

  BaseDialogInterface::BaseDialogInterface(const BaseDialogInterface &) = default;

  BaseDialogInterface::~BaseDialogInterface() = default;
  // End BaseDialoginterface


  // Client
  Client::Client() = default;

  Client::Client(const string &uname)
  :username(uname)
  {}

  Client::Client(const string &uname, const string &current_quest_name)
  :username(uname), currentQuestName(current_quest_name)
  {}

  Client::Client(const Client &o) = default;

  Client::~Client() = default;

  spClient Client::createClient(const string &uname)
  {
    return make_shared<Client>(uname);
  }

  spClient Client::createClient(const string &uname, const string &current_quest_name)
  {
    return make_shared<Client>(uname, current_quest_name);
  }
  // End Client


  // Request
  Request::Request()
  = default;

  Request::Request(const Request& o)
  = default;

  Request::~Request()
  = default;
  // End Request


  // UnexpectedDialog
  UnexpectedDialog::UnexpectedDialog() = default;
  UnexpectedDialog::UnexpectedDialog(const UnexpectedDialog&) = default;
  UnexpectedDialog::~UnexpectedDialog() = default;

  spBotResponse UnexpectedDialog::handleMessage(botserver::spRequest &request)
  {
      DEBUG_STRUCT_LOG("UnexpectedDialog::handleMessage");

      return BotResponse::makeResponse("Не понимаю о чём речь");
  }
  // End UnexpectedDialog


  // BotResponse
  BotResponse::BotResponse() = default;

  BotResponse::BotResponse(const string& text)
  :text(text) {}

  BotResponse::BotResponse(const string& text, const ButtonsType& buttons )
  :text(text), buttons(buttons) {}

  BotResponse::BotResponse(const BotResponse &o) = default;

  BotResponse::~BotResponse() = default;

  string BotResponse::getJsonString()
  {
    DEBUG_STRUCT_LOG("BotResponse::getJsonString()");

    json j = *this;
    return j.dump();
  }

  spBotResponse BotResponse::makeResponse(const string& text)
  {
    return make_shared<BotResponse>(text);
  }

  spBotResponse BotResponse::makeResponse(const string& text, const ButtonsType& buttons)
  {
    return make_shared<BotResponse>(text, buttons);
  }
  // End BotResponse


  // Button
  Button::Button() = default;
  Button::Button(const Button &o) = default;
  Button::~Button() = default;
  // End Button




  // Quest
  Quest::Quest() = default;

  Quest::Quest(const string &title, const string &description, const string &first_dialog_name)
  : _dialogs(), _title(title), _description(description), _first_dialog(first_dialog_name)
  {
  }

  Quest::Quest(const Quest &o) :
  _dialogs(o._dialogs), _title(o._title), _description(o._description), _first_dialog(o._first_dialog),
  _dialogs_m()
  {}

  Quest::~Quest() = default;

  spQuest Quest::makeQuest()
  {
      spQuest ret = make_shared<Quest>();
      return ret;
  }

  spBaseDialogInterface Quest::findDialog(const string &name) const
  {
      const auto &dialog_it = _dialogs.find(name);

      if (dialog_it == _dialogs.end())
      {
          return getDefaultDialog();
      }
      return dialog_it->second;
  }


  spBaseDialogInterface Quest::getDefaultDialog() const
  {
      // Dialog not found, get entrypoint
      const auto &entrypoint_dialog = getFirstDialog();
      if (!entrypoint_dialog)
      {
          // dialog not found,
          // handle unexpected dialog
          return UnexpectedDialog::getInstance();
      }
      return entrypoint_dialog;
  }


  void Quest::addDialog(const string &name, const spBaseDialogInterface &dialog)
  {
      if (_dialogs.find(name) != _dialogs.end())
      {
          lock_guard<mutex> lg(_dialogs_m);

          _dialogs[name] = dialog;
      }
  }

  void Quest::setDialogs(const unordered_map<string, spBaseDialogInterface> &dialogs)
  {
      lock_guard<mutex> lg(_dialogs_m);

      _dialogs = dialogs;
  }


  void Quest::clearDialogs()
  {
      lock_guard<mutex> lg(_dialogs_m);

      _dialogs.clear();
  }

  spQuest Quest::makeQuest(const string &title, const string &description, const string &first_dialog_name)
  {
      auto ret = make_shared<Quest>(title, description, first_dialog_name);
      return ret;
  }

  // Get entry point to quest
  spBaseDialogInterface Quest::getFirstDialog() const
  {
      // Try to find dialog by name
      for (const auto &pair : _dialogs)
      {
          if (pair.second->GetName() == _first_dialog)
          {
              return pair.second;
          }
      }

      // try to find dialog by type (1 - start messaging dialog)
      for (const auto &pair : _dialogs)
      {
          if (pair.second->getDialogType() == 1)
          {
              return pair.second;
          }
      }

      // not found
      return nullptr;
  }

  spBotResponse Quest::handleMessage(botserver::spRequest &request)
  {
      const spClient &client = request->getClient();
      const auto &current_dialog = client->getCurrentDialog();

      if (!current_dialog)
      {
          const auto &dialog = getDefaultDialog();
          return dialog->handleMessage(request);
      }

      const auto &message = request->getUserInboxMessage();
      const ButtonsType &btns = current_dialog->getButtons();

      for (const Button &btn : btns)
      {
          const string &button_command = btn.getCommand();
          const string &message_command = message->getCommand();

          // if passed command available in commands from buttons
          if (button_command == message_command)
          {
              // Than received valid dialog name via message command

              const auto &next_dialog = findDialog(message_command);

              auto response = next_dialog->handleMessage(request);

              // after it done, client moved to next dialog.
              client->setCurrentDialog(next_dialog);

              return response;
          }
      }

      // We are not found command in available commands in buttons, say it.
      auto& unexpected_dialog = UnexpectedDialog::getInstance();
      return unexpected_dialog->handleMessage(request);
  }
  // End Quest



  // UserInboxMessage
  UserInboxMessage::UserInboxMessage() = default;

  UserInboxMessage::UserInboxMessage(const nlohmann::json& json_dialog)
  {
    from_json(json_dialog, *this);
  }

  UserInboxMessage::UserInboxMessage(const UserInboxMessage &o) = default;

  UserInboxMessage::~UserInboxMessage() = default;

  spUserInboxMessage UserInboxMessage::parseFromString(const string &data)
  {
    json j;
    try
    {
      j = json::parse(data);
      auto parsed_inbox_message = j.get<UserInboxMessage>();

      auto sp_inbox_msg = make_shared<UserInboxMessage>(parsed_inbox_message);

      return sp_inbox_msg;
    }
    catch (json::parse_error &ex)
    {
      botserver::Error::sendError(
        fmt::format("ERROR: parse error at byte {}", ex.byte
      ));

      return nullptr;
    } catch (json::exception &ex)
    {
      botserver::Error::sendError(
        fmt::format("ERROR: json exception error: {}", ex.what())
      );
      return nullptr;
    }

    botserver::Error::sendError("ERROR: unextected error, end of UserInboxMessage::parseFromString function");
    return nullptr;
  }
  // End UserInboxMessage



  // QuestStorage
  QuestStorage::QuestStorage() = default;

  QuestStorage::QuestStorage(const QuestStorage &o) :
  _quests_map(o._quests_map), _quests_map_m() {}

  QuestStorage::~QuestStorage() = default;

  QuestStorage &QuestStorage::getInstance()
  {
      static QuestStorage singletone;
      return singletone;
  }

  spQuest QuestStorage::findQuest(const string &name) const
  {
      const auto &quest_it = _quests_map.find(name);
      if (quest_it == _quests_map.end())
      {
          // quest not found
          return nullptr;
      }
      return quest_it->second;
  }

  bool QuestStorage::delQuest(const string &name)
  {
      if (_quests_map.find(name) != _quests_map.end())
      {
          lock_guard<mutex> lg(_quests_map_m);

          const auto deleted_count = _quests_map.erase(name);
          return deleted_count != 0;
      }
      return false;
  }

  void QuestStorage::setQuests(const QuestMapType& quests)
  {
      lock_guard<mutex> lg(_quests_map_m);

      _quests_map = quests;
  }

  spQuest QuestStorage::getDefaultQuest() const
  {
      // FIXME: Currently first available quest.
      for (auto& pair : _quests_map)
      {
          return pair.second;
      }
      return nullptr;
  }
  // End QuestStotage



  // ClientStorage
  ClientStorage::ClientStorage() = default;

  ClientStorage::ClientStorage(const ClientStorage& o) :
  clients(o.clients), _clients_m() {}

  ClientStorage::~ClientStorage() = default;


  spClient ClientStorage::FindClient(const string &name) const
  {
      // clients.at(name);
      const auto &client_it = clients.find(name);
      if (client_it == clients.end())
      {
          // not found
          return nullptr;
      }
      return client_it->second;
  }

  bool ClientStorage::DelClient(const string &name)
  {
      if (clients.find(name) != clients.end())
      {
          lock_guard<mutex> lg(_clients_m);

          const auto count_deleted = clients.erase(name);
          return count_deleted != 0;
      }
      return false;
  }

  void ClientStorage::AddClient(spClient &client)
  {
      lock_guard<mutex> lg(_clients_m);

      clients[client->getUsername()] = client;
  }
  // End ClientStorage


}
