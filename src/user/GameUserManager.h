/*
 * File:   GameUserManager.h
 * Author: ns
 *
 * Created on July 5, 2020, 10:09 PM
 */

#ifndef GAMEUSERMANAGER_H
#define GAMEUSERMANAGER_H

#include <unordered_map>
#include <string>
#include "GameUser.h"


class GameUserManager {
public:

    inline void addUser(spGameUser user)
    {
        _users_table[user->getUsername()] = user;
    }

    inline spGameUser getUser(const std::string& uname)
    {
        return _users_table[uname];
    }

    inline void clearAll()
    {
        _users_table.clear();
    }

    static GameUserManager& getInstance();

private:
    GameUserManager();

    GameUserManager(const GameUserManager&);

    virtual ~GameUserManager();

    static std::unordered_map<std::string, spGameUser> _users_table;
};

#endif /* GAMEUSERMANAGER_H */
