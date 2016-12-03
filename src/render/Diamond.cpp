#include "Diamond.h"

int Render::Diamond::getWidth() {
    return this->map->cols * this->tileWidth;
}

int Render::Diamond::getHeight() {
    return this->map->rows * this->tileHeight;
}

int Render::Diamond::getTileWidth() {
    return this->tileWidth;
}

int Render::Diamond::getTileHeight() {
    return this->tileHeight;
}

void Render::Diamond::render(int posX, int posY) {

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    Render::Tile * render = new Render::Tile();
    Tiles::DiamondView * dm = new Tiles::DiamondView();

    // x e y de destino do tile
    int x0, y0;

    for (int x = 0; x < this->map->cols; x++) {

        for (int y = 0; y < this->map->rows; y++) {

            // calcTilePosition
            x0 = x * this->tileWidth/2 - y * this->tileWidth/2;
            y0 = x * this->tileHeight/2 + y * this->tileHeight/2;

            dm->calcTilePosition(x, y, this->tileWidth, this->tileHeight, x0, y0);
            Tiles::Tile * tile = tileSet->getTileById( this->map->getTileId(x,y));
            render->render(tile, this->tileWidth, this->tileHeight, posX + x0, posY + y0);

            // aproveita o "for" para desenhar o cursor quando necessario
            if (x == this->cursorX && y == this->cursorY) {
                render->setColor(0,1,0);
                render->render(tile, this->tileWidth, this->tileHeight, posX + x0, posY + y0 );
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

    // regra para nao deixar o usuario mover alem do diamond para os lados
    // se o x ou y for invalido, nada acontece

    if ( this->cursorX >= this->map->cols
      || this->cursorX < 0
      || this->cursorY >= this->map->rows
      || this->cursorY < 0)
    {
        this->cursorY = bkpY;
        this->cursorX = bkpX;
    }

    printf("%i-%i\n", this->cursorX, this->cursorY);

}

void Render::Diamond::moveCursorToAxis(int x, int y) {
    // @todo encontrar tile a partir do x e y

    int r = 0;
    int c = 0;

    printf("%i-%i = %i,%i\n", x, y, r , c);

    this->cursorY = r;
    this->cursorX = c;

}
