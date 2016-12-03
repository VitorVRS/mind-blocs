#include "TileMap.h"

Tiles::TileMap::TileMap() {}

Tiles::TileMap::TileMap(int cols, int rows) {
    this->tiles = new unsigned int[cols*rows];
}

Tiles::TileMap::~TileMap() {

    if (this->tiles == nullptr) {
        return;
    }

    delete this->tiles;
}

int Tiles::TileMap::getTileId(int x, int y) {
    return this->tiles[x + y * cols];
}

int Tiles::TileMap::getCols() {
    return this->cols;
}

int Tiles::TileMap::getRows() {
    return this->rows;
}
