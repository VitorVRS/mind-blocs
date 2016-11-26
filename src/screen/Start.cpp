#include "Start.h"

#include <iostream>
#include "../tiles/Tile.h"
#include "../render/Tile.h"

void Screen::Start::execute() const {

    Tiles::Tile * t1 = new Tiles::Tile(1);
    Tiles::Tile * t2 = new Tiles::Tile(1);

    Render::Tile * render = new Render::Tile();
    render->render(t1, 100, 100);
    render->render(t2, 200, 200);

    delete t1;
    delete t2;
    delete render;
}