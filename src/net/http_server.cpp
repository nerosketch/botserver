#include <httplib.h>
#include "http_server.h"
#include "urls.h"

httplib::Server _svr;


LocalHttpServer::LocalHttpServer()
= default;

LocalHttpServer::~LocalHttpServer()
= default;


void LocalHttpServer::stopSignal()
{
  _svr.stop();
}


botserver::spError LocalHttpServer::Serve(const char *host, int port, int socket_flags)
{
  // HTTPS
  //httplib::SSLServer svr;

  for (const auto &i : urls)
  {
    _svr.Post(i.url.c_str(), i.handle);
  }

  if (!_svr.listen(host, port))
  {
    return botserver::Error::makeError("Error listen http", 0);
  }

  return nullptr;
}
