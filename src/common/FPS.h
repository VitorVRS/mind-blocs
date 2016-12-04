#ifndef FPS_H
#define FPS_H

#include "Timer.h"

class FPS {

private:
    double time;
    int fps;
    int ticks;

public:
    FPS();
    void tick(double time);
    int getFPS();

};

#endif // FPS_H