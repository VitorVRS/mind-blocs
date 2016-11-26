#ifndef TILE_MAP_HEADER
#define TILE_MAP_HEADER

#include <string>

namespace Tiles {

class TileMap {
private:
    unsigned int * tiles;
    int cols;
    int rows;
public:
    TileMap();
    TileMap(int cols, int rows);
    ~TileMap();
    int getTileId(int x, int y);
    void loadFromFile(std::string file);
    int getCols();
    int getRows();

};

};

#endif
