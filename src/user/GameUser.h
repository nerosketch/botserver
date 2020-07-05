/*
 * File:   GameUser.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:56 PM
 */

#ifndef GAMEUSER_H
#define GAMEUSER_H

#include <string>
#include <memory>
#include "../quest/GeneralInboxGameMessage.h"

class GameUser
{
public:
  GameUser ();
  GameUser (const GameUser& orig);
  virtual ~GameUser ();

  inline std::string& getUsername()
  {
    return _username;
  }
  inline void setUsername(const std::string& uname)
  {
    _username = uname;
  }
  
  void on_inbox_message(GeneralInboxGameMessage& msg);
  
private:
  std::string _username;
  
};
typedef std::shared_ptr<GameUser> spGameUser;

#endif /* GAMEUSER_H */
