/*
 * File:   GameInboxMessage.h
 * Author: ns
 *
 * Created on July 6, 2020, 1:09 PM
 */

#ifndef GAMEINBOXMESSAGE_H
#define GAMEINBOXMESSAGE_H

#include <string>

class GameInboxMessage {
public:
    explicit GameInboxMessage(const std::string& msg);

    GameInboxMessage(const GameInboxMessage& o);

    virtual ~GameInboxMessage();

    void setMessage(const std::string& msg);

    std::string& getMessage();

    bool operator==(const GameInboxMessage& r) const;

    bool operator!=(const GameInboxMessage& r) const;


private:
    std::string _msg;
};

#endif /* GAMEINBOXMESSAGE_H */
