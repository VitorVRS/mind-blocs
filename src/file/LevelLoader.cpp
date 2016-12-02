#include "LevelLoader.h"
#include <iostream>
#include <fstream>

LevelLoader::LevelLoader(std::string path) {
    this->path = path;
}

t_tile_map LevelLoader::getTileMap() {
    t_tile_map tileMap;
    std::ifstream file(this->path.c_str());
    if (file.is_open()) {
        file >> tileMap.cols;
        file >> tileMap.rows;

        tileMap.tiles[tileMap.cols * tileMap.rows];

        int value;
        for (int i = 0; i < tileMap.cols; i++) {
            for (int j = 0; j < tileMap.rows; j++) {
                file >> value;
                tileMap.tiles[i + j * tileMap.cols] = value;
            }
        }

        file >> tileMap.minimum_time;
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    return tileMap;
}
