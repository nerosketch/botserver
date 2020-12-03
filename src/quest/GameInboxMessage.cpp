/*
 * File:   GameInboxMessage.cpp
 * Author: ns
 *
 * Created on July 6, 2020, 1:09 PM
 */

#include "GameInboxMessage.h"

GameInboxMessage::GameInboxMessage(const std::string &msg)
    : _msg(msg)
{
}
GameInboxMessage::GameInboxMessage(const GameInboxMessage &o) = default;
GameInboxMessage::~GameInboxMessage() = default;

void GameInboxMessage::setMessage(const std::string &msg)
{
    _msg = msg;
}

std::string &GameInboxMessage::getMessage()
{
    return _msg;
}

bool GameInboxMessage::operator==(const GameInboxMessage &r) const
{
    return r._msg == _msg;
}

bool GameInboxMessage::operator!=(const GameInboxMessage &r) const
{
    return r._msg != _msg;
}
