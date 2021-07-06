#ifndef BotServerCore_H
#define BotServerCore_H

#include <string>
#include <unordered_map>
#include <utility>
#include <mutex>
#include <nlohmann/json.hpp>
#include <httplib.h>
#include "preprocessors.h"

using namespace std;
using nlohmann::json;



namespace botserver {

  // shared_ptr decls
  DECLARE_SMART(Error, spError);
  DECLARE_SMART(HandlerInterface, spHandlerInterface);
  DECLARE_SMART(BaseDialogInterface, spBaseDialogInterface);
  DECLARE_SMART(Client, spClient);
  DECLARE_SMART(Request, spRequest);
  DECLARE_SMART(BaseMessageInterface, spBaseMessageInterface);
  DECLARE_SMART(UnexpectedDialog, spUnexpectedDialog);
  DECLARE_SMART(BotResponse, spBotResponse);
  DECLARE_SMART(Button, spButton);
  DECLARE_SMART(Quest, spQuest);
  DECLARE_SMART(UserInboxMessage, spUserInboxMessage);
  DECLARE_SMART(QuestStorage, spQuestStorage);



  // Errors
  class Error
  {
  public:
    Error();
    Error(const string &msg, int err_code);
    Error(const Error &);
    virtual ~Error();

    static spError makeError(const string &msg, int err_code = 0);

    static void sendError(spError err);
    static void sendError(const string &msg, int err_code = 0);

    const string& getMsg() const
    {
      return message_text;
    }

  protected:
    string message_text;
    int error_num;
  };
  // End Errors



  // HandlerInterface
  class HandlerInterface {
  public:
    virtual spBotResponse handleMessage(spRequest &request) = 0;

  };
  // End HandlerInterface



  // Button
  class Button
  {
  public:
    Button();
    Button(const Button &);
    virtual ~Button();

    inline const string& GetTitle() const
    {
      return title;
    }

    inline void setTitle(const string& title)
    {
      this->title = title;
    }

    inline const string& getNextDialogName() const
    {
      return next_dialog_name;
    }

    inline void setNextDialogName(const string& next_dialog_name)
    {
      this->next_dialog_name = next_dialog_name;
    }

    friend ostream& operator<<(ostream& os, const Button& me)
    {
      os << me.title << " " << me.next_dialog_name;
      return os;
    }

    inline const string& getCommand() const
    {
      return command;
    }

    inline void setCommand(const string &cmd)
    {
      command = cmd;
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Button, title, next_dialog_name, command)

  private:
    string title;
    string next_dialog_name;
    string command;
  };

  typedef vector<Button> ButtonsType;
  // End Button




  // BaseDialoginterface
  class BaseDialogInterface : public HandlerInterface
  {
  public:
    BaseDialogInterface();
    BaseDialogInterface(const nlohmann::json& json_dialog);
    BaseDialogInterface(const BaseDialogInterface &);
    virtual ~BaseDialogInterface();

    const string& GetName() const
    {
      return name;
    }

    inline void SetName(const string& name)
    {
      this->name = name;
    }

    inline uint16_t getDialogType() const
    {
      return dialog_type;
    }

    inline void setDialogType(uint16_t dialogType)
    {
      this->dialog_type = dialogType;
    }

    inline const string& getMessage() const
    {
      return message;
    }

    inline void setMessage(const string& message)
    {
      this->message = message;
    }

    inline ButtonsType& getButtons()
    {
      return buttons;
    }

    inline void setButtons(const ButtonsType &btns)
    {
      buttons = btns;
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BaseDialogInterface, name, dialog_type, message, buttons)

  private:
    string name;
    uint16_t dialog_type;
    string message;
    ButtonsType buttons;
  };
  // End BaseDialoginterface


  // Client
  class Client
  {
  public:
    Client();
    Client(const string &uname);
    Client(const string &uname, const spQuest &current);
    Client(const Client &);
    virtual ~Client();

    static spClient createClient(const string &uname);
    static spClient createClient(const string &uname, const spQuest &current_quest);

    inline const string& getUsername() const
    {
      return username;
    }

    inline void setUsername(const string& username)
    {
      this->username = username;
    }

    inline const spQuest& getCurrentQuest() const
    {
      return currentQuest;
    }

    inline void setCurrentQuest(const spQuest& current_quest)
    {
      currentQuest = current_quest;
    }

    inline const spBaseDialogInterface& getCurrentDialog() const
    {
      return current_dialog;
    }

    inline void setCurrentDialog(const spBaseDialogInterface &dialog)
    {
      current_dialog = dialog;
    }

  private:
    string username;
    spQuest currentQuest;
    spBaseDialogInterface current_dialog;
  };
  // End Client



  // Request
  class Request {
  public:
    Request();
    Request(const Request&);
    virtual ~Request();

    inline spClient& getClient()
    {
      return client;
    }
    inline void setClient(spClient &client)
    {
      this->client = client;
    }

    inline spUserInboxMessage& getUserInboxMessage()
    {
      return message;
    }
    inline void setMessage(spUserInboxMessage &message)
    {
      this->message = message;
    }

    inline const httplib::Request *getHttpRequestPtr() const
    {
      return p_http_request;
    }
    inline void setHttpRequestPtr(const httplib::Request *p_req)
    {
      p_http_request = p_req;
    }

    inline spQuest &getCurrentQuest()
    {
      return current_quest;
    }
    inline void setCurrentQuest(const spQuest &quest)
    {
      current_quest = quest;
    }

  private:
    spClient client;
    spUserInboxMessage message;
    const httplib::Request *p_http_request;
    spQuest current_quest;
  };
  // End Request


  // BaseMessageInterface
  class BaseMessageInterface {
  public:

    virtual spBotResponse onMessageHandler(const std::string &data, botserver::spRequest &request) = 0;

  };
  // End BaseMessageInterface


  // UnexpectedDialog
  class UnexpectedDialog : public BaseDialogInterface
  {
  public:
    UnexpectedDialog();
    UnexpectedDialog(const UnexpectedDialog &);
    virtual ~UnexpectedDialog();
    UnexpectedDialog &operator=(const UnexpectedDialog &);

    inline static spUnexpectedDialog& getInstance()
    {
      static spUnexpectedDialog dialog;
      if (!dialog)
      {
        dialog = make_shared<UnexpectedDialog>();
      }
      return dialog;
    }

    spBotResponse handleMessage(botserver::spRequest &request) override;
  };
  // End UnexpectedDialog


  // BotResponse
  class BotResponse
  {
  public:
    BotResponse();
    BotResponse(const string& text);
    BotResponse(const string& text, const ButtonsType& buttons );
    BotResponse(const BotResponse &);
    virtual ~BotResponse();

    string GetText() const
    {
      return text;
    }

    void SetText(string text)
    {
      this->text = text;
    }

    const ButtonsType& GetButtons() const
    {
      return buttons;
    }

    void SetButtons(const ButtonsType& buttons)
    {
      this->buttons = buttons;
    }

    string getJsonString();

    static spBotResponse makeResponse(const string& text);
    static spBotResponse makeResponse(const string& text, const ButtonsType& buttons);

    inline bool hasError() const
    {
      return error.get() != nullptr;
    }
    inline void setError(const botserver::spError &err)
    {
      error = err;
    }
    inline const botserver::spError &getError() const
    {
      return error;
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BotResponse, text, buttons)

  protected:
    string text;
    ButtonsType buttons;

    botserver::spError error;
  };
  // End BotResponse




  // Quest
  class Quest : public HandlerInterface
  {
  public:
      Quest();
      Quest(const string &title, const string &description, const string &first_dialog_name = "start");
      Quest(const Quest &o);

      static spQuest makeQuest();
      static spQuest makeQuest(const string &title, const string &description, const string &first_dialog_name = "start");

      virtual ~Quest();

      spBaseDialogInterface findDialog(const string &name) const;
      spBaseDialogInterface getDefaultDialog() const;

      void addDialog(const string &name, const spBaseDialogInterface &dialog);

      void setDialogs(const unordered_map<string, spBaseDialogInterface> &dialogs);

      void clearDialogs();

      // Get entry point to quest
      spBaseDialogInterface getFirstDialog() const;

      spBotResponse handleMessage(botserver::spRequest &request) override;

      const string& GetTitle() const
      {
          return _title;
      }

      void Set_title(const string& title)
      {
          _title = title;
      }
      const string& GetDescription() const
      {
          return _description;
      }

      void SetDescription(const string& description)
      {
          _description = description;
      }
      const string& GetFirstDialog() const
      {
          return _first_dialog;
      }

      void Set_first_dialog(const string& first_dialog)
      {
          _first_dialog = first_dialog;
      }

  private:
      string _title;
      string _description;
      string _first_dialog;
      unordered_map<string, spBaseDialogInterface> _dialogs;

      mutex _dialogs_m;
  };
  // End Quest



  // UserInboxMessage
  class UserInboxMessage
  {
  public:
    UserInboxMessage();
    UserInboxMessage(const nlohmann::json& json_dialog);
    UserInboxMessage(const UserInboxMessage &);
    virtual ~UserInboxMessage();

    inline const string &getUname() const
    {
      return uname;
    }

    inline void setUname(const string &uname)
    {
      this->uname = uname;
    }

    inline const string &getText() const
    {
      return text;
    }
    inline void setText(const string &text)
    {
      this->text = text;
    }

    inline const string& getCommand() const
    {
      return command;
    }
    inline void setCommand(const string& cmd)
    {
      command = cmd;
    }

    static spUserInboxMessage parseFromString(const string &data);

  private:
    string uname;
    string text;
    string command;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(UserInboxMessage, uname, text, command)
  };
  // End UserInboxMessage



  // QuestStorage
  typedef unordered_map<string, spQuest> QuestMapType;

  class QuestStorage
  {
  public:
      static QuestStorage &getInstance();

      spQuest findQuest(const string &name) const;
      bool delQuest(const string &name);
      void setQuests(const QuestMapType& quests);
      spQuest getDefaultQuest() const;

  private:
      QuestStorage();
      QuestStorage(const QuestStorage &);
      virtual ~QuestStorage();
      QuestStorage &operator=(const QuestStorage &);

      QuestMapType _quests_map;

      mutex _quests_map_m;
  };
  // End QuestStorage



  // ClientStorage
  class ClientStorage
  {
  public:
      static ClientStorage &getInstance()
      {
          static ClientStorage singletone;
          return singletone;
      }

      spClient FindClient(const string& name) const;
      bool DelClient(const string& name);
      void AddClient(spClient& client);

  private:
      ClientStorage();
      ClientStorage(const ClientStorage &);
      virtual ~ClientStorage();
      ClientStorage &operator=(const ClientStorage &);

      unordered_map<string, spClient> clients;

      mutex _clients_m;
  };  
  // End ClientStorage

};

#endif