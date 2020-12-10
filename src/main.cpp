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

#include "core/server.h"

using namespace std;

// #define OUT(msg) std::cout << "======================" << std::endl; msg; std::cout << std::endl;

SockServer srv;

void sigend_function(int)
{
  srv.stopSignal();
}

int main(int argc, char **argv)
{

  signal(SIGINT, sigend_function);
  // signal(SIGQUIT, [](int) { cout << "SIGQUIT" << endl; });
  // signal(SIGHUP, [](int) { cout << "SIGHUP" << endl; });
  signal(SIGTERM, sigend_function);  // kill <pid> signal
  // signal(SIGKILL, [](int) { cout << "SIGILL" << endl; });

  auto err = srv.Serve(3142, [] {
    sd_notifyf(0, "READY=1\n"
                  "STATUS=Server is up! Listening...\n"
                  "MAINPID=%lu",
                  (unsigned long) getpid()
    );
  });

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

  return 0;
}
