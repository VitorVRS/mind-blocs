#ifndef FPS_H
#define FPS_H

#include "Timer.h"

class FPS {

private:
    Timer * timer;
    double time;
    int fps;
    int ticks;

public:
    FPS();
    ~FPS();
    void tick();
    int getFPS();

};

#endif // FPS_H