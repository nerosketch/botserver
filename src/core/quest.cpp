/*
 * File:   quest.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:55 PM
 */

#include "quest.h"
#include "unexpected_dialog.h"

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
        //not found
        return nullptr;
    }
    return dialog_it->second;
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

void Quest::SerializeMe(std::istream &in)
{
    // TODO: Make serialize for this
}

void Quest::DeserializeMe(std::ostream &out)
{
    // TODO: Make deserialize for this
}

spBotResponse Quest::HandleMessage(botserver::spRequest &request)
{
    const spClient &client = request->getClient();
    const auto &current_dialog = client->getCurrentDialog();
    const auto &message = request->getUserInboxMessage();
    const ButtonsType &btns = current_dialog->getButtons();

    Тут current_dialog не заполнен когда новый клиент, и когда первое сообщение.
    Надо разобраться

    for (const Button &btn : btns)
    {
        const string &button_command = btn.getCommand();
        const string &message_command = message->getCommand();

        // if passed command available in commands from buttons
        if (button_command == message_command)
        {
            // Than received valid dialog name via message command

            // Find dialog by message command
            const auto &next_dialog_it = _dialogs.find(message_command);

            if (next_dialog_it == _dialogs.end())
            {
                // Dialog not found, get entrypoint
                const auto &entrypoint_dialog_it = getFirstDialog();
                if (!entrypoint_dialog_it)
                {
                    // dialog not found,
                    // handle unexpected dialog
                    auto& unexpected_dialog = UnexpectedDialog::getInstance();
                    return unexpected_dialog.HandleMessage(request);
                }
                return entrypoint_dialog_it->HandleMessage(request);
            }

            // Allow to handle message
            const auto &next_dialog = next_dialog_it->second;
            auto response = next_dialog->HandleMessage(request);

            // after it done, client moved to next dialog.
            client->setCurrentDialog(next_dialog);

            return response;
        }
    }

    // We are not found command in available commands in buttons, say it.
    auto& unexpected_dialog = UnexpectedDialog::getInstance();
    return unexpected_dialog.HandleMessage(request);
}
