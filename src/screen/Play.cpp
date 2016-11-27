#include "Play.h"

#include "GLFW/glfw3.h"
#include <iostream>

Screen::Play::Play() {

    Tiles::TileMap * map = new Tiles::TileMap();
    map->loadFromFile("resources/map1.txt");

    this->dm = new Render::Diamond(map, Game::TILE_WIDTH);
    this->menu = new Render::Menu();
}

void Screen::Play::show(int winWidth, int winHeight) const {
    this->dm->render(winWidth, winHeight);
    this->menu->render();
}

void Screen::Play::keypress(int key, int scancode, int mods) const {
    printf("%i - %s\n", key, "pressed");

    switch (key) {

        // menu keybindings
        case GLFW_KEY_LEFT:
            this->menu->change(Direction::WEST);
        break;

        case GLFW_KEY_RIGHT:
            this->menu->change(Direction::EAST);
        break;
        // end menu keybindings

        // diamond keybindings
        case GLFW_KEY_W:
            this->dm->move(Direction::NORTH);
        break;

        case GLFW_KEY_S:
            this->dm->move(Direction::SOUTH);
        break;

        case GLFW_KEY_A:
            this->dm->move(Direction::WEST);
        break;

        case GLFW_KEY_D:
            this->dm->move(Direction::EAST);
        break;

        case GLFW_KEY_Q:
            this->dm->move(Direction::NORTHWEST);
        break;

        case GLFW_KEY_E:
            this->dm->move(Direction::NORTHEAST);
        break;

        case GLFW_KEY_Z:
            this->dm->move(Direction::SOUTHWEST);
        break;

        case GLFW_KEY_C:
            this->dm->move(Direction::SOUTHEAST);
        break;
        // end diamond keybindings


    }

}