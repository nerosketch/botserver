/* 
 * File:   main.cpp
 * Author: ns
 *
 * Created on June 14, 2020, 8:39 PM
 */

//#include <cstdlib>
#include <iostream>
//#include "core/PrimaryServer.h"
#include "GameConfig.h"
#include "httpserver/HttpServerScgi.h"


// using namespace std;

// #define OUT(msg) std::cout << "======================" << std::endl; msg; std::cout << std::endl;



int main (int argc, char** argv)
{
    // game_config is defined in "HttpServerScgi.h"
    game_config.load_config("config-example.conf");

    const VkConfig& vk = game_config.get_vk_config();

    std::cout << "VkApi key: " << vk.get_api_key() << std::endl;

    HttpServerScgi hs;
    hs.run();

    return 0;
}
