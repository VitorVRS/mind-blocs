#ifndef RENDER_TILE_HEADER
#define RENDER_TILE_HEADER

#include "../tiles/Tile.h"
#include <GL/gl.h>

namespace Render {

class Tile {

public:
    void render(Tiles::Tile * tile, GLfloat x, GLfloat y);

};

};

#endif //RENDER_TILE_HEADER
