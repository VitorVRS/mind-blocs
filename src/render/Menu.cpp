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

        if (this->selected == i) {
            render->setColor(0,1,0);
            render->render(tiles.at(i), width, height, i * width, 10);
            render->clearColor();
        }

    }

    delete render;

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

int Render::Menu::getSelected() {
    return this->selected;
}