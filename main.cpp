#include <iostream>

#include "src/file/PTMFileReader.h"
#include "src/common/SpriteLoader.h"
#include "src/Game.h"

#include "src/file/MapFileLoader.h"

void loadTileMap() {
    File::t_tile_map map;

    File::getMapFile("./resources/maps/level01.map", map);

    std::cout << map.cols << std::endl;
    std::cout << map.rows << std::endl;
    std::cout << map.minimum_time << std::endl;
}

int main(int argc,  char** argv) {
    loadTileMap();

    Game mindBlocs = Game();

    mindBlocs.setPosition(300, 200);
    mindBlocs.setSize(800, 600);
    mindBlocs.setTitle((char *) "Mind Blocs");
    mindBlocs.init();

    return 0;
}
