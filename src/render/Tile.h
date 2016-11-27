#ifndef RENDER_TILE_HEADER
#define RENDER_TILE_HEADER

#include "../tiles/Tile.h"
#include <GL/gl.h>

namespace Render {

class Tile {

private:
    GLfloat r, g, b;
    bool customColor;

public:
    void render(Tiles::Tile * tile, GLfloat width, GLfloat height, GLfloat x, GLfloat y);
    void setColor(GLfloat r, GLfloat g, GLfloat b);
    void clearColor();
};

};

#endif //RENDER_TILE_HEADER
