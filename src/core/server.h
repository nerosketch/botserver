#ifndef BOTSERVER_H
#define BOTSERVER_H

#include <netinet/in.h>
#include "errors.h"
#include "../third_party/tcp_server.h"

DECLARE_SMART(SockServer, spSockServer);

class SockServer {
public:
  SockServer();

  virtual ~SockServer();

  spErrorBase Serve(in_port_t port);

  void stopSignal()
  {
    p_server->setSigStop();
  }

private:
  TcpServer* p_server;

  SockServer(const SockServer&);
  SockServer operator=(const SockServer&);
};
#endif /* BOTSERVER_H */
