/*
 * File:   quest.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:55 PM
 */

#ifndef GAMEQUEST_H
#define GAMEQUEST_H

#include <string>
#include <unordered_map>
#include <utility>
#include <mutex>
#include "preprocessors.h"
#include "base_dialog.h"
#include "BaseSerializedObject.h"

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

    virtual ~Quest();

    spBaseDialogInterface findDialog(const string &name) const;

    void addDialog(const string &name, const spBaseDialogInterface &dialog);

    void setDialogs(const unordered_map<string, spBaseDialogInterface> &dialogs);

    void clearDialogs();

    // Get entry point to quest
    spBaseDialogInterface getFirstDialog() const;

    void SerializeMe(std::istream &in) override;
    void DeserializeMe(std::ostream &out) override;

    spBotResponse HandleMessage(spClient &client, spUserInboxMessage &msg) const override;

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

#endif /* GAMEQUEST_H */
