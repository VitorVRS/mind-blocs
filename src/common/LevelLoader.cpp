#include "LevelLoader.h"
#include <string>

LevelLoader::LevelLoader(unsigned int startLevel) {
    this->currentLevel = startLevel;
}

void LevelLoader::setCurrentLevel(Tiles::TileMap *map) {
    File::getMapFile("./resources/maps/level" + std::to_string(this->currentLevel) + ".map", map);
}

void LevelLoader::incrementLevel() {
    this->currentLevel += 1;
}

void LevelLoader::setLevel(unsigned int level) {
    this->currentLevel = level;
}
