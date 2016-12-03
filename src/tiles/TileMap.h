#ifndef TILE_MAP_HEADER
#define TILE_MAP_HEADER

#include <string>

namespace Tiles {

class TileMap {
public:
    unsigned int * tiles;
    int cols;
    int rows;
    int minimumTime;
    TileMap();
    TileMap(int cols, int rows);
    ~TileMap();
    int getTileId(int x, int y);
    int getCols();
    int getRows();

};

};

#endif
