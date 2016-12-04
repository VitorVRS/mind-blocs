#include "Timer.h"

void Timer::start() {
    this->begin = glfwGetTime();
}

void Timer::stop() {
    this->end = glfwGetTime();
}

double Timer::getElapsedTime() {
    return double(this->end - this->begin);
}
