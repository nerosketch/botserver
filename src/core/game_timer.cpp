/*
 * File:   GameTimer.cpp
 * Author: ns
 * 
 * Created on June 30, 2020, 12:19 AM
 */

#include "game_timer.h"

using namespace std;

// GameTimer::GameTimer() = default;
// GameTimer::GameTimer(const GameTimer &o) = default;
// GameTimer::~GameTimer() = default;

void GameTimer::wait_run(const chrono::microseconds& delay, const GameTimerFunc& callback)
{
  this_thread::sleep_for(delay);
  callback();
}

thread GameTimer::await_run(const chrono::microseconds& delay, const GameTimerFunc& callback)
{
  auto t = thread([&]() {
    this_thread::sleep_for(delay);
    callback();
  });
  t.detach();
  return t;
}
