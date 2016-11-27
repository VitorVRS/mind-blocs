#include "Diamond.h"

void Render::Diamond::render() {

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    Render::Tile * render = new Render::Tile();
    Tiles::DiamondView * dm = new Tiles::DiamondView();

    int x0, y0;
    for (int x = 0; x < this->map->getCols(); x++) {

        for (int y = 0; y < this->map->getRows(); y++) {

            dm->calcTilePosition(x, y, 64, 32, x0, y0);
            render->render( tileSet->getTileById( this->map->getTileId(x,y) ), x0, y0 );

        }

    }

    delete render;
    delete dm;

}