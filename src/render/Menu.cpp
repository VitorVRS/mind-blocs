#include "Menu.h"

#include <iostream>

Render::Menu::Menu() {
    this->selected = 0;
}

void Render::Menu::render() {

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();

    std::vector<Tiles::Tile*> tiles = tileSet->getTiles();

    Render::Tile * render = new Render::Tile();

    int width = Game::TILE_WIDTH;
    int height = width/2;

    for (int i = 0; i < tiles.size(); i++) {
        render->render(tiles.at(i), width, height, i * width, 10);
    }

    delete render;

    this->drawCursor();

}

void Render::Menu::change(Direction direction) {

    switch (direction) {
        case Direction::WEST:
            this->selected--;
            break;
        case Direction::EAST:
            this->selected++;
            break;
    }

    if (this->selected < 0) {
        this->selected = 0;
    }

    Tiles::TileSet * tileSet = Tiles::TileSet::getInstance();
    std::vector<Tiles::Tile*> tiles = tileSet->getTiles();


    if (this->selected >= tiles.size()) {
        this->selected = tiles.size() - 1;
    }

}

void Render::Menu::drawCursor() {

    glColor3f(0, 1.0, 0);

    int width = Game::TILE_WIDTH;

    glBegin(GL_QUADS);
        glVertex2f(this->selected * width, 10);
        glVertex2f(this->selected * width + width, 10);
        glVertex2f(this->selected * width + width, 15);
        glVertex2f(this->selected * width, 15);
    glEnd();

}