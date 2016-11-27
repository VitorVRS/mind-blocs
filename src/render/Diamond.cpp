#include "Diamond.h"

void Render::Diamond::render(int winWidth, int winHeight) {

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    Render::Tile * render = new Render::Tile();
    Tiles::DiamondView * dm = new Tiles::DiamondView();

    int xIni = winWidth/2 - this->tileWidth / 2;
    int yIni = winHeight/2 - this->map->getRows() * this->tileHeight / 2;

    int x0, y0;
    for (int x = 0; x < this->map->getCols(); x++) {

        for (int y = 0; y < this->map->getRows(); y++) {

            dm->calcTilePosition(x, y, this->tileWidth, this->tileHeight, x0, y0);
            Tiles::Tile * tile = tileSet->getTileById( this->map->getTileId(x,y));
            render->render(tile, this->tileWidth, this->tileHeight, xIni + x0, yIni + y0 );

            if (x == this->cursorX && y == this->cursorY) {
                render->setColor(0,1,0);
                render->render(tile, this->tileWidth, this->tileHeight, xIni + x0, yIni + y0 );
                render->clearColor();
            }

        }

    }

    delete render;
    delete dm;
}

void Render::Diamond::move(Direction direction) {

    int bkpX = this->cursorX;
    int bkpY = this->cursorY;

    switch (direction) {

        case Direction::NORTH:
            this->cursorX++;
            this->cursorY++;
        break;

        case Direction::SOUTH:
            this->cursorX--;
            this->cursorY--;
        break;

        case Direction::WEST:
            this->cursorX--;
            this->cursorY++;
        break;

        case Direction::EAST:
            this->cursorX++;
            this->cursorY--;
        break;

        case Direction::NORTHWEST:
            this->cursorY++;
        break;

        case Direction::NORTHEAST:
            this->cursorX++;
        break;

        case Direction::SOUTHWEST:
            this->cursorX--;
        break;

        case Direction::SOUTHEAST:
            this->cursorY--;
        break;
    }

    if ( this->cursorX >= this->map->getCols()
      || this->cursorX < 0
      || this->cursorY >= this->map->getRows()
      || this->cursorY < 0)
    {
        this->cursorY = bkpY;
        this->cursorX = bkpX;
    }

    printf("%i-%i\n", this->cursorX, this->cursorY);

}