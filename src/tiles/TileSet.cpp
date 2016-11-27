#include "TileSet.h"

Tiles::Tile * Tiles::TileSet::getTileById(int id) {

    for (int i = 0; i < this->tiles.size(); i++) {
        if (id == this->tiles[i]->getId()) {
            return this->tiles[i];
        }
    }

    return nullptr;
};

void Tiles::TileSet::addTile(Tiles::Tile * tile) {
    this->tiles.push_back(tile);
}

Tiles::TileSet * Tiles::TileSet::instance = nullptr;

Tiles::TileSet *  Tiles::TileSet::getInstance() {

    if (instance == nullptr) {
        instance = new Tiles::TileSet();
    }

    return instance;
}