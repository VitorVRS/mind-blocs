#ifndef RENDER_HAND_HEADER
#define RENDER_HAND_HEADER

#include "../file/PTMFileReader.h"
#include "../common/SpriteLoader.h"

namespace Render {

class Hand {

private:

    const int FPS = 12; // @todo aplicar a animacao a este FPS

    int currentFrame;
    double elapsedTime;
    Animation * animation;

public:

    Hand();
    ~Hand();

    void render(int x, int y);
    void addTime(double time);
};

};

#endif // RENDER_HAND_HEADER