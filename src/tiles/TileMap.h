#ifndef TILE_MAP_HEADER
#define TILE_MAP_HEADER

namespace Tiles {

class TileMap {
private:
    unsigned int * map;
    int cols;
    int rows;
public:
    int getTileId(int x, int y);

};

};

#endif
