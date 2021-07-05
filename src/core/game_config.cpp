/*
 * File:   GameConfig.cpp
 * Author: ns
 * 
 * Created on July 3, 2020, 12:26 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unordered_map>
#include <libconfig.h++>
#include "game_config.h"

using namespace std;
using namespace libconfig;

GameConfig &game_config = GameConfig::getInstance();

VkConfig::VkConfig() = default;

VkConfig::VkConfig(const VkConfig &o) = default;

VkConfig::~VkConfig() = default;

ScgiConfig::ScgiConfig() = default;

ScgiConfig::ScgiConfig(const ScgiConfig &o)
{
}

ScgiConfig::~ScgiConfig() = default;

GameConfig::GameConfig() = default;

GameConfig::GameConfig(const GameConfig &o)
{
}

GameConfig::~GameConfig() = default;

int GameConfig::load_config(const char *fname)
{
    Config cfg;

    try
    {
        cfg.readFile(fname);
    }
    catch (const FileIOException &fioex)
    {
        cerr << "I/O error while reading file." << endl;
        return (EXIT_FAILURE);
    }
    catch (const ParseException &pex)
    {
        cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
             << " - " << pex.getError() << endl;
        return (EXIT_FAILURE);
    }

    const Setting &root = cfg.getRoot();

    // Получить некое название.
    try
    {
        string greet = root.lookup("greeting");
        cout << "Store greeting: " << greet << endl
             << endl;
    }
    catch (const SettingNotFoundException &nfex)
    {
        cerr << "No 'greeting' setting in configuration file." << endl;
    }

    const Setting &app = root.lookup("application");

    try
    {
        const Setting &vk_settings = app.lookup("vk");
        const string &hash = vk_settings["api_key"];
        _vk.set_api_key(hash);
    }
    catch (const SettingNotFoundException &nfex)
    {
        cerr << "No 'application.vk' setting in configuration file." << endl;
    }

    // Get scgi params
    try
    {
        const Setting &conf = app.lookup("scgi");
        const string &ip = conf["ip"];
        _scgi.set_host(ip);
        int port = conf["port"];
        u_short sport = port;
        _scgi.set_port(sport);
    }
    catch (const SettingNotFoundException &nfex)
    {
        cerr << "No 'application.scgi' setting in configuration file." << endl;
    }

    // Get storage params
    try
    {
        const Setting &conf = app.lookup("storage");
        const string &store_type = conf["type"];

        /*const unordered_map<string, StorageConfigType> storage_types_map = {
            {"file", StorageConfigType::FILE},
        };

        const auto storage_types_map_it = storage_types_map.find(store_type);
        if (storage_types_map_it == storage_types_map.end())
        {
            // Set default storage type
            _storage_config.set_type(StorageConfigType::FILE);
        }
        else
        {
            auto storage_type = storage_types_map_it->second;
            _storage_config.set_type(storage_type);
        }*/
    }
    catch (const SettingNotFoundException &nfex)
    {
        cerr << "No 'application.scgi' setting in configuration file." << endl;
    }

    return (EXIT_SUCCESS);
}

GameConfig &GameConfig::getInstance()
{
    static GameConfig _inst;
    return _inst;
}
