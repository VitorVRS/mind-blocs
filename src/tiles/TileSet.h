#ifndef TILE_SET_HEADER
#define TILE_SET_HEADER

#include "Tile.h"
#include <vector>

namespace Tiles {

class TileSet {
private:
    std::vector<Tiles::Tile*> tiles;

public:
    Tiles::Tile * getTileById(int id);
    void addTile(Tiles::Tile * tile);
};

};

#endif
