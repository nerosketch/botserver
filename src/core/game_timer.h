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

class GameTimer
{
public:
    // GameTimer();
    // GameTimer(const GameTimer&);
    // virtual ~GameTimer();

    static void wait_run(std::chrono::microseconds delay, std::function<void()> callback);

    static std::thread await_run(std::chrono::microseconds delay, std::function<void()> callback);
};

#endif /* GAMETIMER_H */
