#ifndef LEVEL_LOADER_H
#define LEVEL_LAODER_H

#include "../file/MapFileLoader.h"

class LevelLoader {
 private:
    unsigned int currentLevel;
 public:
    LevelLoader(unsigned int startLevel);
    void setCurrentLevel(Tiles::TileMap *map);
    void incrementLevel();
    void setLevel(unsigned int level);
};

#endif
