#ifndef Urls_H
#define Urls_H

#include <string>
#include <httplib.h>
#include "http_handlers.h"

using namespace httplib;

struct U {
  std::string url;
  Server::Handler handle;

  U(const std::string &url, Server::Handler &handler) :
  url(url), handle(handler)
  {}
};


static const struct U urls[] = {
  U( "/entrypoint/", entrypoint_handler ),
};


#endif /* Urls_H */