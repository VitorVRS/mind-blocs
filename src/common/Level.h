#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "../tiles/TileMap.h"

class Level {

private:
    Tiles::TileMap * map;

public:
    Level(Tiles::TileMap * map) : map(map) {};
    ~Level();
    bool validate(Tiles::TileMap * their);
    Tiles::TileMap * getTileMap();
};

#endif