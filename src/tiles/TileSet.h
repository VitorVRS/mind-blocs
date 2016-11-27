#ifndef TILE_SET_HEADER
#define TILE_SET_HEADER

#include "Tile.h"
#include <vector>

namespace Tiles {

class TileSet {
private:
    static TileSet * instance;
    std::vector<Tiles::Tile*> tiles;

    // singleton
    TileSet() {};
    TileSet(TileSet const&);
    void operator=(TileSet const&);

public:
    Tiles::Tile * getTileById(int id);
    void addTile(Tiles::Tile * tile);
    std::vector<Tiles::Tile*> getTiles();

    static TileSet * getInstance();
};

};

#endif
