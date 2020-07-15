/*
 * File:   VKApi.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:58 PM
 */

#ifndef VKAPI_H
#define VKAPI_H

#include <string>
#include "BaseAPI.h"

class VKApi : public IBaseAPI {
public:
    VKApi();

    VKApi(const VKApi& o);

    virtual ~VKApi();

    virtual void
    on_get_message(const RequestParamsMap& params, const std::string& query_string, char* buffUot) override;

    virtual void
    on_post_message(const RequestParamsMap& params, const std::string& post_data, const std::string& query_string,
            char* buffUot) override;

    virtual int setWebhook(const std::string& url) override;

private:

};

#endif /* VKAPI_H */

