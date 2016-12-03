#ifndef MAP_FILE_LOADER_H
#define MAP_FILE_LOADER_H

#include <string>
#include "../tiles/TileMap.h"

namespace File {
    void getMapFile(std::string path, Tiles::TileMap *tileMap);
}

#endif
