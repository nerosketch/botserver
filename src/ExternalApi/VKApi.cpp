/*
 * File:   VKApi.cpp
 * Author: ns
 * 
 * Created on June 29, 2020, 10:58 PM
 */

#include <string>
#include <string.h>
#include "VKApi.h"

using namespace std;

VKApi::VKApi()
{
}

VKApi::VKApi(const VKApi& o)
{
}

VKApi::~VKApi()
{
}

void VKApi::on_get_message(const RequestParamsMap& params, const string& query_string, char* buffUot)
{
    strcpy(buffUot, "{"
                    "\"It is a VK up\": true"
                    "}"
    );
}

void VKApi::on_post_message(const RequestParamsMap& params, const string& post_data, const string& query_string,
        char* buffUot)
{

}

int VKApi::setWebhook(const string& url)
{
    return 0;
}
