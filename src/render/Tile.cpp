#include "Tile.h"

#include <iostream>
#include <GL/gl.h>

void Render::Tile::render(Tiles::Tile * tile, GLfloat width, GLfloat height, GLfloat x, GLfloat y) {


    glColor3f(1.0/tile->getId(), 1.0/tile->getId(), 1.0/tile->getId());

    if (this->customColor) {
        glColor3f(this->r, this->g, this->b);
    }

    glBegin(GL_QUADS);
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

void Render::Tile::setColor(GLfloat r, GLfloat g, GLfloat b) {

    this->r = r;
    this->g = g;
    this->b = b;
    this->customColor = true;
}
void Render::Tile::clearColor() {
    this->customColor = false;
}