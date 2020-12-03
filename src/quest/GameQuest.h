/*
 * File:   GameQuest.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:55 PM
 */

#ifndef GAMEQUEST_H
#define GAMEQUEST_H

#include <string>
#include <unordered_map>
#include <utility>
#include "SingleDialog.h"
#include "../core/BaseSerializedObject.h"

using namespace std;

class GameQuest;
typedef shared_ptr<GameQuest> spGameQuest;

class GameQuest : public BaseSerializedObject
{
public:
    GameQuest();
    GameQuest(const string &title, const string &description, const string &first_dialog_name = "start");
    GameQuest(const GameQuest &o);

    static spGameQuest makeGameQuest();
    static spGameQuest makeGameQuest(const string &title, const string &description, const string &first_dialog_name = "start");

    ~GameQuest() override;

    inline spSingleDialog findDialog(const string &name)
    {
        return _dialogs[name];
    }
    inline void addDialog(const string &name, const spSingleDialog &dialog)
    {
        _dialogs[name] = dialog;
    }
    inline void clearDialogs()
    {
        _dialogs.clear();
    }

    // Get entry point to quest
    spSingleDialog &getFirstDialog();

    void SerializeMe(std::istream &in) override;
    void DeserializeMe(std::ostream &out) override;

private:
    string _title;
    string _description;
    string _first_dialog;
    unordered_map<string, spSingleDialog> _dialogs;
};

#endif /* GAMEQUEST_H */
