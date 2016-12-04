#include "FPS.h"

#include <iostream>

FPS::FPS() {
    this->fps = 0;
    this->ticks = 0;
}

void FPS::tick(double time) {

    this->time += time;

    if (this->time >= 1.0) {
        this->fps = this->ticks;
        this->ticks = 0;
        this->time = this->time - 1.0;
    }

    this->ticks++;
}

int FPS::getFPS() {
    return this->fps;
}