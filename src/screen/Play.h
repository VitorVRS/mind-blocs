#ifndef SCREEN_START_HEADER
#define SCREEN_START_HEADER

#include "IScreen.h"
#include "../common/Direction.h"
#include "../render/Diamond.h"
#include "../render/Menu.h"
#include "../tiles/TileMap.h"
#include "../Game.h"

namespace Screen {

class Play: public IScreen {

private:
    Render::Diamond * dm;
    Render::Menu * menu;

public:
    Play();
    void show() const;
    void keypress(int key, int scancode, int mods) const;

};

}

#endif //SCREEN_START_HEADER
