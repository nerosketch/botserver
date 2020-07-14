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

class ScgiConfig
{
public:
  ScgiConfig();
  virtual ~ScgiConfig();

  const std::string& get_host() const
  {
    return host;
  }
  void set_host(const std::string& _host)
  {
    host = _host;
  }
  const u_short get_port() const
  {
    return port;
  }
  void set_port(u_short _port)
  {
    port = _port;
  }
  
private:
  ScgiConfig (const ScgiConfig&);

  std::string host;
  u_short port;
};


class GameConfig
{
public:

  int load_config(const char* fname);

  const VkConfig& get_vk_config() const
  {
    return _vk;
  }
  const ScgiConfig& get_scgi_config() const
  {
    return _scgi;
  }

  static GameConfig& getInstance();

private:
  GameConfig ();
  GameConfig (const GameConfig& o);
  virtual ~GameConfig ();

  VkConfig _vk;
  ScgiConfig _scgi;
};

extern GameConfig& game_config;

#endif /* GAMECONFIG_H */
