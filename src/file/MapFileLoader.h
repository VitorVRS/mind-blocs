#ifndef MAP_FILE_LOADER_H
#define MAP_FILE_LOADER_H

#include <string>

namespace File {
  typedef struct {
    int cols;
    int rows;
    unsigned int* tiles;
    int minimum_time;
  } t_tile_map;

  void getMapFile(std::string path, t_tile_map &tileMap);

}

#endif
