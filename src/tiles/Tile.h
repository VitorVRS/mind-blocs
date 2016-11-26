#ifndef TILE_HEADER
#define TILE_HEADER

#include "../render/Image.h"

namespace Tiles {

class Tile {
private:
    int id;
    unsigned texId;

public:
    Tile(int id) : id(id) {};
    Tile(int id, unsigned texId) : id(id), texId(texId) {};
    int getId();
    unsigned getTexId();
};

};

#endif
