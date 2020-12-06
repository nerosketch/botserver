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

volatile sig_atomic_t already_stopped_flag = 0;

SockServer srv;

void sigint_function(int sig)
{
  if (already_stopped_flag == 1)
  {
    cout << "Already stopped" << endl;
    return;
  }
  already_stopped_flag = 1;
  srv.stopSignal();
}

int main(int argc, char **argv)
{

  signal(SIGINT, sigint_function);

  auto err = srv.Serve(3142);
  if (err)
  {
    cerr << "Error: " << err << endl;
    return -1;
  }
  return 0;
}
