#include "Diamond.h"

void Render::Diamond::render() {

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    Render::Tile * render = new Render::Tile();
    Tiles::DiamondView * dm = new Tiles::DiamondView();

    // @todo remover daqui, isso eh apenas para centralizar a imagem na tela
    int xIni = 400 - (this->map->getCols() * this->tileWidth / 2);
    int yIni = 300 - ((this->map->getRows() / 2 - 1) * this->tileHeight / 2);

    int x0, y0;
    for (int x = 0; x < this->map->getCols(); x++) {

        for (int y = 0; y < this->map->getRows(); y++) {

            dm->calcTilePosition(x, y, this->tileWidth, this->tileHeight, x0, y0);
            Tiles::Tile * tile = tileSet->getTileById( this->map->getTileId(x,y));
            render->render(tile, this->tileWidth, this->tileHeight, xIni + x0, yIni + y0 );

        }

    }

    delete render;
    delete dm;

}