/*
 * File:   TelegramAPI.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:59 PM
 */

#include <string.h>
#include "TelegramAPI.h"

TelegramAPI::TelegramAPI () { }

TelegramAPI::TelegramAPI (const TelegramAPI& orig) { }

TelegramAPI::~TelegramAPI () { }

void TelegramAPI::on_get_message(const RequestParamsMap& params, const std::string& query_string, char *buffUot)
{
    strcpy(buffUot, "{"
        "\"It is a Telegram up\": true"
        "}"
    );
}
void TelegramAPI::on_post_message(const RequestParamsMap& params, const std::string& post_data, const std::string& query_string, char *buffUot)
{
  
}
