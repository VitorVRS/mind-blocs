#include "Play.h"

#include "GLFW/glfw3.h"
#include <iostream>

Screen::Play::Play() {
    this->current = new Tiles::TileMap();
    this->loader = new LevelLoader(1);

    this->loader->setCurrentLevel(this->current);

    this->dm = new Render::Diamond(this->current, Game::TILE_WIDTH);
    this->menu = new Render::Menu();
}

void Screen::Play::show() {

    // valor utilizado para somar ao x e y
    // para centralizar o diamond
    int posX = this->getWidth()/2 - this->dm->getTileWidth() / 2;
    int posY = this->getHeight()/2 - this->dm->getHeight() / 2;

    this->dm->render(posX, posY);
    this->menu->render();
}

void Screen::Play::click(double x, double y, int mods) {


    int posX = this->getWidth()/2 - this->dm->getWidth() / 2;
    int posY = this->getHeight()/2 - this->dm->getHeight() / 2;

    if (x - posX < 0 || x - posX >= this->dm->getWidth()) {
        return;
    }

    if (y - posY < 0 || y - posY >= this->dm->getHeight()) {
        return;
    }

    this->dm->moveCursorToAxis(x - posX, y - posY);
}

void Screen::Play::keypress(int key, int scancode, int mods) {
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
