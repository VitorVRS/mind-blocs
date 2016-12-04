#include "Text.h"
#include <iostream>

Render::Text::Text(std::string text, unsigned int x, unsigned int y) {
    this->text = text;
    this->posX = x;
    this->posY = y;
}

void Render::Text::setText(std::string text) {
    this->text = text;
}

void Render::Text::render() {

    // color and position
    glColor3f(0.2f, 0.2f, 0.2f);
    glRasterPos2f(this->posX, this->posY);

    // workaround
    glDisable(GL_TEXTURE_2D);

    // glc render
    glcRenderString(this->text.c_str());

    // workaround
    glEnable(GL_TEXTURE_2D);

};

void Render::Text::setX(unsigned int x) {
    this->posX = x;
};

void Render::Text::setY(unsigned int y) {
    this->posY = y;
};