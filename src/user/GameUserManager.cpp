/*
 * File:   GameUserManager.cpp
 * Author: ns
 * 
 * Created on July 5, 2020, 10:09 PM
 */

#include "GameUserManager.h"


std::unordered_map<std::string, spGameUser> GameUserManager::_users_table;

GameUserManager::GameUserManager()
{
}

GameUserManager::GameUserManager(const GameUserManager& orig)
{
}

GameUserManager::~GameUserManager()
{
}


GameUserManager& GameUserManager::getInstance()
{
    static GameUserManager _inst;
    return _inst;
}
