#ifndef RENDER_DIAMOND_HEADER
#define RENDER_DIAMOND_HEADER

#include "Tile.h"
#include "../tiles/TileMap.h"
#include "../tiles/TileSet.h"
#include "../tiles/DiamondView.h"

namespace Render {

class Diamond {

private:
    Tiles::TileMap * map;

public:
    Diamond(Tiles::TileMap * map) : map(map) {};
    void render();
};

};

#endif // RENDER_VIEW_HEADER