#include <iostream>

#include "src/file/PTMFileReader.h"
#include "src/common/SpriteLoader.h"
#include "src/Game.h"


int main(int argc,  char** argv) {

    Game mindBlocs = Game();

    mindBlocs.setPosition(300, 200);
    mindBlocs.setSize(800, 600);
    mindBlocs.setTitle((char *) "Mind Blocs");
    mindBlocs.init();

    return 0;
}
