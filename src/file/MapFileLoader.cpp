#include "MapFileLoader.h"
#include <iostream>
#include <fstream>

void File::getMapFile(std::string path, t_tile_map &tileMap) {
  std::ifstream file = std::ifstream(path.c_str());
  if (file.is_open()) {
    file >> tileMap.cols;
    file >> tileMap.rows;

    tileMap.tiles = new unsigned int[tileMap.cols * tileMap.rows];

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
}
