#include "Tile.h"

int Tiles::Tile::getId() {
    return this->id;
}

Render::Image * Tiles::Tile::getImage() {
    return this->image;
}
