/*
 * File:   GameConfig.h
 * Author: ns
 *
 * Created on July 3, 2020, 12:26 AM
 */

#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>
#include "storage/GameStorage.h"


class VkConfig {
public:
    VkConfig();

    virtual ~VkConfig();

    void set_api_key(const std::string& key)
    {
        api_key = key;
    }

    const std::string& get_api_key() const
    {
        return api_key;
    }

private:
    VkConfig(const VkConfig&);

    std::string api_key;

};

class ScgiConfig {
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

    u_short get_port() const
    {
        return port;
    }

    void set_port(u_short _port)
    {
        port = _port;
    }

private:
    ScgiConfig(const ScgiConfig&);

    std::string host;
    u_short port{};
};


class StorageConfig {
public:
    StorageConfig() : _type(StorageConfigType::FILE) {}

    virtual ~StorageConfig() = default;

    inline void set_type(const StorageConfigType& type)
    {
        _type = type;
    }

    inline const StorageConfigType& get_type() const
    {
        return _type;
    }

private:
    StorageConfig(const StorageConfig&) = default;

    StorageConfigType _type;
//    std::string _type;
};


class GameConfig {
public:

    int load_config(const char* fname);

    static GameConfig& getInstance();

    const VkConfig& get_vk_config() const
    {
        return _vk;
    }

    const ScgiConfig& get_scgi_config() const
    {
        return _scgi;
    }

    const StorageConfig& get_storage_config() const
    {
        return _storage_config;
    };

private:
    GameConfig();

    GameConfig(const GameConfig& o);

    virtual ~GameConfig();

    VkConfig _vk;
    ScgiConfig _scgi;
    StorageConfig _storage_config;
};

extern GameConfig& game_config;

#endif /* GAMECONFIG_H */
