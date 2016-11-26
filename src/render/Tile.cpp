#include "Tile.h"

#include <iostream>
#include <GL/gl.h>

void Render::Tile::render(Tiles::Tile * tile, GLfloat x, GLfloat y) {

    GLfloat width = 64;
    GLfloat height = width / 2;

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);

        //@todo glBindTexture <- tile->getTexId();

        // glTexCoord2f(0.0f, 1.0f);
        glVertex2f(x, height / 2 + y);

        // glTexCoord2f(1.0f, 1.0f);
        glVertex2f(height + x, height + y);

        // glTexCoord2f(1.0f, 0.0f);
        glVertex2f(width + x, height / 2 + y);

        // glTexCoord2f(0.0f, 0.0f);
        glVertex2f(height + x, y);

    glEnd();

};