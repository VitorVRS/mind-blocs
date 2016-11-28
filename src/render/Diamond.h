#ifndef RENDER_DIAMOND_HEADER
#define RENDER_DIAMOND_HEADER

#include "../common/Direction.h"
#include "Tile.h"
#include "../tiles/TileMap.h"
#include "../tiles/TileSet.h"
#include "../tiles/DiamondView.h"

namespace Render {

class Diamond {

private:
    Tiles::TileMap * map;
    int tileWidth, tileHeight;
    int cursorX, cursorY;

public:
    Diamond(Tiles::TileMap * map, int tileWidth) :
        map(map),
        tileWidth(tileWidth),
        tileHeight(tileWidth/2),
        cursorX(0),
        cursorY(0)
    {};
    void render(int winWidth, int winHeight);
    void move(Direction direction);
    void moveCursorToAxis(int x, int y);
    int getWidth();
    int getHeight();
    int getTileWidth();
    int getTileHeight();
};

};

#endif // RENDER_VIEW_HEADER