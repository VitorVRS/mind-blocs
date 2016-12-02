#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <string>

typedef struct {
    int cols;
    int rows;
    unsigned int tiles[];
    int minimum_time;
} t_tile_map;

class LevelLoader {
 public:
    LevelLoader(std::string path);
    t_tile_map getTileMap();
 private:
    std::string path;
};

#endif
