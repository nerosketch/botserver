/*
 * File:   VKApi.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:58 PM
 */

#include <string.h>
#include "VKApi.h"

VKApi::VKApi () { }

VKApi::VKApi (const VKApi& o) { }

VKApi::~VKApi () { }

void VKApi::on_get_message(const RequestParamsMap& params, const std::string& query_string, char *buffUot)
{
    strcpy(buffUot, "{"
        "\"It is a VK up\": true"
        "}"
    );
}
void VKApi::on_post_message(const RequestParamsMap& params, const std::string& post_data, const std::string& query_string, char *buffUot)
{
  
}
