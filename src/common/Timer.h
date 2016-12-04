//
// Created by VitorVRS on 9/30/16.
//

#ifndef STAR_EXPLORER_TIMER_H
#define STAR_EXPLORER_TIMER_H

#include <GLFW/glfw3.h>

class Timer {
private:
    double begin;
    double end;

public:
    void start();
    void stop();
    double getElapsedTime();
};

#endif //STAR_EXPLORER_TIMER_H
