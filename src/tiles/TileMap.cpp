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

void Tiles::TileMap::loadFromFile(std::string file) {
    // @todo carregar arquivo do mapa de tiles;
    //
    // remover isso aqui, ´e apenas para exemplo

    this->cols = 5;
    this->rows = 5;

    this->tiles = new unsigned int[cols*rows];

    for (int x = 0; x<this->cols;x++) {
        for (int y = 0; y<this->rows;y++) {
            this->tiles[x + y * this->cols] = x+1;
        }

    }

}

int Tiles::TileMap::getCols() {
    return this->cols;
}

int Tiles::TileMap::getRows() {
    return this->rows;
}