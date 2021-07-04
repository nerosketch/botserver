/* 
 * File:   main.cpp
 * Author: ns
 *
 * Created on June 14, 2020, 8:39 PM
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <systemd/sd-daemon.h>

#include <net/http_server.h>

using namespace std;

// #define OUT(msg) std::cout << "======================" << std::endl; msg; std::cout << std::endl;

spLocalHttpServer http_srv;

void sigend_function(int)
{
  if(http_srv) {
    http_srv->stopSignal();
  }
}

int main(int argc, char **argv)
{

  signal(SIGINT, sigend_function);
  // signal(SIGQUIT, [](int) { cout << "SIGQUIT" << endl; });
  // signal(SIGHUP, [](int) { cout << "SIGHUP" << endl; });
  signal(SIGTERM, sigend_function);  // kill <pid> signal
  // signal(SIGKILL, [](int) { cout << "SIGILL" << endl; });

  http_srv = LocalHttpServer::getInstance();

  sd_notifyf(0, "READY=1\n"
                "STATUS=Server is up! Listening...\n"
                "MAINPID=%lu",
                (unsigned long) getpid()
  );
  auto err = http_srv->Serve("localhost", 8083);

  // https://www.freedesktop.org/software/systemd/man/sd_notify.html
  sd_notify(0, "STOPPING=1");

  if (err)
  {
    cerr << "Error: " << err << endl;
    sd_notifyf(0, "STATUS=%s", err->getMsg().c_str());
    return -1;
  } else {
    sd_notify(0, "STATUS=I'm done. Thnx.");
  }

  cout << "Bye :)" << endl;
  return 0;
}
