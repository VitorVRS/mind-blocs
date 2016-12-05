#include "Level.h"

Level::~Level() {
    delete this->map;
}

bool Level::validate(Tiles::TileMap * their) {

    if (their->cols != map->cols) {
        return false;
    }

    if (their->rows != map->rows) {
        return false;
    }

    for (int i = 0; i < map->cols; i++) {

        for (int j = 0; j < map->rows; j++) {

            if ( their->tiles[i + j * their->cols] != map->tiles[i + j * map->cols] ) {
                return false;
            }

        }

    }

    return true;
}

Tiles::TileMap * Level::getTileMap() {
    return this->map;
}
