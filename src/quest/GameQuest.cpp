/*
 * File:   GameQuest.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:55 PM
 */

#include "GameQuest.h"

GameQuest::GameQuest() :
        _dialogs(), _title(), _description(), _first_dialog()
{
}
GameQuest::GameQuest(const string& title, const string& description, const string& first_dialog_name) :
        _dialogs(), _title(title), _description(description), _first_dialog(first_dialog_name)
{}


GameQuest::GameQuest(const GameQuest& o) = default;

GameQuest::~GameQuest() = default;
