#ifndef LocalHttpServer_H
#define LocalHttpServer_H


#include <core/preprocessors.h>
#include <core/errors.h>
#include <string>

using namespace std;


DECLARE_SMART(LocalHttpServer, spLocalHttpServer);

class LocalHttpServer {
public:
  LocalHttpServer();
  virtual ~LocalHttpServer();

  spError Serve(const char *host, int port, int socket_flags = 0);

  static spLocalHttpServer getInstance()
  {
    return make_shared<LocalHttpServer>();
  }

  void stopSignal();

private:
  LocalHttpServer(const LocalHttpServer&) = delete;
};

#endif /* LocalHttpServer_H */
