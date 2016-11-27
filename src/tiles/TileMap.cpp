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

    this->cols = 4;
    this->rows = 4;

    this->tiles = new unsigned int[cols*rows];

    this->tiles[0] = 1;
    this->tiles[1] = 2;
    this->tiles[2] = 3;
    this->tiles[3] = 4;

    this->tiles[4] = 1;
    this->tiles[5] = 2;
    this->tiles[6] = 3;
    this->tiles[7] = 4;

    this->tiles[8]  = 5;
    this->tiles[9]  = 6;
    this->tiles[10] = 5;
    this->tiles[11] = 6;

    this->tiles[12] = 5;
    this->tiles[13] = 4;
    this->tiles[14] = 3;
    this->tiles[15] = 2;

}

int Tiles::TileMap::getCols() {
    return this->cols;
}

int Tiles::TileMap::getRows() {
    return this->rows;
}