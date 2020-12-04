/*
 * File:   quest.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:55 PM
 */

#ifndef GAMEQUEST_H
#define GAMEQUEST_H

#include "preprocessors.h"
#include <string>
#include <unordered_map>
#include <utility>
#include "base_dialog.h"
#include "../core/BaseSerializedObject.h"

using namespace std;

DECLARE_SMART(Quest, spQuest);

class Quest : public BaseSerializedObject, public HandlerInterface
{
public:
    Quest();
    Quest(const string &title, const string &description, const string &first_dialog_name = "start");
    Quest(const Quest &o);

    static spQuest makeQuest();
    static spQuest makeQuest(const string &title, const string &description, const string &first_dialog_name = "start");

    ~Quest() override;

    spBaseDialogInterface findDialog(const string &name);

    inline void addDialog(const string &name, const spBaseDialogInterface &dialog)
    {
        _dialogs[name] = dialog;
    }

    inline void clearDialogs()
    {
        _dialogs.clear();
    }

    // Get entry point to quest
    spBaseDialogInterface getFirstDialog();

    void SerializeMe(std::istream &in) override;
    void DeserializeMe(std::ostream &out) override;

    spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) override;

private:
    string _title;
    string _description;
    string _first_dialog;
    unordered_map<string, spBaseDialogInterface> _dialogs;
};

#endif /* GAMEQUEST_H */
