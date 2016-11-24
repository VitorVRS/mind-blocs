#ifndef TILE_HEADER
#define TILE_HEADER

#include "../render/Image.h"

namespace Tiles {

class Tile {
private:
    int id;
    Render::Image * image;

public:
    Tile(int id, Render::Image * image) : id(id), image(image) {};
    int getId();
    Render::Image * getImage();
};

};

#endif
