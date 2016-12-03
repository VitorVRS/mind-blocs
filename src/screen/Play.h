#ifndef SCREEN_START_HEADER
#define SCREEN_START_HEADER

#include "AbstractScreen.h"
#include "../common/Direction.h"
#include "../common/LevelLoader.h"
#include "../render/Diamond.h"
#include "../render/Menu.h"
#include "../render/Hand.h"
#include "../tiles/TileMap.h"
#include "../Game.h"

namespace Screen {

class Play: public AbstractScreen {

private:
    Render::Diamond * dm;
    Render::Menu * menu;
    Render::Hand * hand;

    LevelLoader * loader;
    double elapsedTime;

public:
    Play();
    void show();
    void keypress(int key, int scancode, int mods);
    void click(double x, double y, int mods);
    Tiles::TileMap *current;

};

}

#endif //SCREEN_START_HEADER
