#ifndef SCREEN_START_HEADER
#define SCREEN_START_HEADER

#include "AbstractScreen.h"
#include "../common/Direction.h"
#include "../render/Diamond.h"
#include "../render/Menu.h"
#include "../tiles/TileMap.h"
#include "../Game.h"

namespace Screen {

class Play: public AbstractScreen {

private:
    Render::Diamond * dm;
    Render::Menu * menu;

public:
    Play();
    void show();
    void keypress(int key, int scancode, int mods);
    void click(double x, double y, int mods);

};

}

#endif //SCREEN_START_HEADER
