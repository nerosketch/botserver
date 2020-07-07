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
    GameInboxMessage(const std::string& msg);
    GameInboxMessage(const GameInboxMessage& orig);
    virtual ~GameInboxMessage();

    inline void setMessage(const std::string& msg)
    {
        _msg = msg;
    }
    inline std::string& getMessage()
    {
        return _msg;
    }
    
private:
    std::string _msg;
};

#endif /* GAMEINBOXMESSAGE_H */
