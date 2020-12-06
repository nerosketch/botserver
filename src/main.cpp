/* 
 * File:   main.cpp
 * Author: ns
 *
 * Created on June 14, 2020, 8:39 PM
 */

#include <iostream>
#include <signal.h>

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

  auto err = srv.Serve(3142);
  if (err)
  {
    cerr << "Error: " << err << endl;
    return -1;
  }
  return 0;
}
