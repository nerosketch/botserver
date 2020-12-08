/*
 * File:   GameTimer.h
 * Author: ns
 *
 * Created on June 30, 2020, 12:19 AM
 */

#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <chrono>
#include <functional>
#include <thread>

typedef std::function<void()> GameTimerFunc;

class GameTimer
{
public:
    // GameTimer();
    // GameTimer(const GameTimer&);
    // virtual ~GameTimer();

    static void wait_run(const std::chrono::microseconds& delay, const GameTimerFunc& callback);

    static std::thread await_run(const std::chrono::microseconds& delay, const GameTimerFunc& callback);
};

#endif /* GAMETIMER_H */
