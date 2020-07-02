/*
 * File:   GameConfig.h
 * Author: ns
 *
 * Created on July 3, 2020, 12:26 AM
 */

#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>


class VkConfig
{
public:
  VkConfig ();
  virtual ~VkConfig ();
  
  void set_api_key(const std::string& key)
  {
    api_key = key;
  }
  const std::string& get_api_key() const
  {
    return api_key;
  }
private:
  VkConfig (const VkConfig&);

  std::string api_key;

};


class GameConfig
{
public:
  GameConfig ();
  virtual ~GameConfig ();

  int load_config(const char* fname);

  const VkConfig& get_vk_config() const
  {
    return _vk;
  }

  
private:
  GameConfig (const GameConfig& orig);

  VkConfig _vk;
};

#endif /* GAMECONFIG_H */
