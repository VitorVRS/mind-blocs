#ifndef RENDER_MENU_HEADER
#define RENDER_MENU_HEADER

#include <vector>

#include "Tile.h"
#include "../Game.h"
#include "../common/Direction.h"
#include "../tiles/Tile.h"
#include "../tiles/TileSet.h"

namespace Render {

class Menu {

private:
    int selected;

    void drawCursor();

public:
    Menu();
    void change(Direction direction);
    void render();
    int getSelected();

};

};

#endif //RENDER_MENU_HEADER