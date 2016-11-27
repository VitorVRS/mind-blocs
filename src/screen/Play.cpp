#include "Play.h"

#include "GLFW/glfw3.h"
#include <iostream>

Screen::Play::Play() {

    Tiles::TileMap * map = new Tiles::TileMap();
    map->loadFromFile("resources/map1.txt");

    this->dm = new Render::Diamond(map, Game::TILE_WIDTH);

    this->menu = new Render::Menu();
}

void Screen::Play::show() const {
    this->dm->render();
    this->menu->render();
}

void Screen::Play::keypress(int key, int scancode, int mods) const {
    printf("%i - %s\n", key, "pressed");

    switch (key) {

        case GLFW_KEY_LEFT:
            this->menu->change(Direction::WEST);
        break;

        case GLFW_KEY_RIGHT:
            this->menu->change(Direction::EAST);
        break;

    }

}