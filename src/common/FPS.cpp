#include "FPS.h"

#include <iostream>

FPS::FPS() {
    this->timer = new Timer();
    this->timer->start();
    this->fps = 0;
}

FPS::~FPS() {
    delete this->timer;
}


void FPS::tick() {
    this->timer->stop();

    this->time += this->timer->getElapsedTime();

    if (this->time >= 1.0) {
        this->fps = this->ticks;
        this->ticks = 0;
        this->time = this->time - 1.0;
    }

    this->timer->start();

    this->ticks++;
}

int FPS::getFPS() {
    return this->fps;
}