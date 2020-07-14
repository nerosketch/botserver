/*
 * File:   BaseAPI.h
 * Author: ns
 *
 * Created on July 5, 2020, 2:26 PM
 */

#ifndef BASEAPI_H
#define BASEAPI_H

#include <string>
#include "../global_types.h"

class IBaseAPI
{
private:
  static const std::string _default_content_type;

protected:

  virtual void on_get_message(const RequestParamsMap& params, const std::string& query_string, char *buffUot) = 0;
  virtual void on_post_message(const RequestParamsMap& params, const std::string& post_data, const std::string& query_string, char *buffUot) = 0;

  virtual int setWebhook(const std::string& url) = 0;

public:

  IBaseAPI();
  IBaseAPI(const IBaseAPI& o);
  virtual ~IBaseAPI();

  virtual const std::string& get_content_type_header();

};


#endif /* BASEAPI_H */
