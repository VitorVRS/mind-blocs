#include "AbstractScreen.h"

void Screen::AbstractScreen::setWidth(int width) {
    this->width = width;
}

void Screen::AbstractScreen::setHeight(int height) {
    this->height = height;
}

int Screen::AbstractScreen::getWidth() {
    return this->width;
}

int Screen::AbstractScreen::getHeight() {
    return this->height;
}