/*
 * File:   TelegramAPI.h
 * Author: ns
 *
 * Created on June 29, 2020, 10:59 PM
 */

#ifndef TELEGRAMAPI_H
#define TELEGRAMAPI_H

#include <string>
#include "BaseAPI.h"

class TelegramAPI : public IBaseAPI
{
public:
  TelegramAPI ();
  TelegramAPI (const TelegramAPI& orig);
  virtual ~TelegramAPI ();

  virtual void on_get_message(const RequestParamsMap& params, const std::string& query_string, char *buffUot) override;
  virtual void on_post_message(const RequestParamsMap& params, const std::string& post_data, const std::string& query_string, char *buffUot) override;

private:

};

#endif /* TELEGRAMAPI_H */

