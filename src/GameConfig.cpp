/*
 * File:   GameConfig.cpp
 * Author: ns
 * 
 * Created on July 3, 2020, 12:26 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <libconfig.h++>
#include "GameConfig.h"

using namespace std;
using namespace libconfig;


VkConfig::VkConfig () { }

VkConfig::VkConfig (const VkConfig& o) { }

VkConfig::~VkConfig () { }




GameConfig::GameConfig () { }

GameConfig::GameConfig (const GameConfig& orig) { }

GameConfig::~GameConfig () { }

int GameConfig::load_config(const char* fname)
{
  Config cfg;

  try
  {
    cfg.readFile(fname);
  }
  catch(const FileIOException &fioex)
  {
    cerr << "I/O error while reading file." << endl;
    return(EXIT_FAILURE);
  }
  catch(const ParseException &pex)
  {
    cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << endl;
    return(EXIT_FAILURE);
  }
  
  const Setting& root = cfg.getRoot();
  
  // Получить некое название.
  try
  {
    string greet = root.lookup("greeting");
    cout << "Store greeting: " << greet << endl << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    cerr << "No 'greeting' setting in configuration file." << endl;
  }

  try
  {
    const Setting& vk_settings = root.lookup("application.vk");

    const string& hash = vk_settings["api_key"];
    _vk.set_api_key(hash);
  }
  catch(const SettingNotFoundException &nfex)
  {
    cerr << "No 'application.vk' setting in configuration file." << endl;
  }

  

  return(EXIT_SUCCESS);
}
