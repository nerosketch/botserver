/*
 * File:   GameQuest.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:55 PM
 */

#include "GameQuest.h"

GameQuest::GameQuest() = default;

GameQuest::GameQuest(const string& title, const string& description, const string& first_dialog_name) :
        _dialogs(), _title(title), _description(description), _first_dialog(first_dialog_name)
{}

GameQuest::GameQuest(const GameQuest& o) = default;

GameQuest::~GameQuest() = default;


spGameQuest GameQuest::makeGameQuest()
{
    spGameQuest ret = make_shared<GameQuest>();
    return ret;
}

spGameQuest GameQuest::makeGameQuest(const string& title, const string& description, const string& first_dialog_name)
{
    auto ret = make_shared<GameQuest>(title, description, first_dialog_name);
    return ret;
}


// Get entry point to quest
spSingleDialog& GameQuest::getFirstDialog()
{
    // TODO: Make logic for get first element
    auto first_dialog_it = _dialogs.begin();
    return first_dialog_it->second;
}


void GameQuest::SerializeMe(std::istream& in)
{
    // TODO: Make serialize for this
}

void GameQuest::DeserializeMe(std::ostream& out)
{
    // TODO: Make deserialize for this
}
