#include "Play.h"

#include "GLFW/glfw3.h"
#include <iostream>
#include <iomanip>

Screen::Play::Play() {
    this->current = new Tiles::TileMap();
    this->loader = new LevelLoader(1);

    this->loader->setCurrentLevel(this->current);

    this->hand = new Render::Hand();
    this->dm = new Render::Diamond(this->current, Game::TILE_WIDTH);
    this->menu = new Render::Menu();

    this->score = 1000;
    this->scoreboard = new Render::Text("", 600, 580);

    this->currentTime = 0;

    // fps control
    this->fps = new FPS();
    this->fpsText = new Render::Text("FPS: 0", 10, 580);
}

Screen::Play::~Play() {
    delete this->current;
    delete this->loader;
    delete this->hand;
    delete this->dm;
    delete this->menu;
    delete this->scoreboard;
    delete this->fps;
    delete this->fpsText;
}


void Screen::Play::show(double time) {

    // valor utilizado para somar ao x e y
    // para centralizar o diamond
    int posX = this->getWidth()/2 - this->dm->getTileWidth() / 2;
    int posY = this->getHeight()/2 - this->dm->getHeight() / 2;

    // draw diamond
    this->dm->render(posX, posY);

    // draw menu
    this->menu->render();


    // start calculation for hand position
    int x, y;
    this->dm->calcTilePosition(this->dm->getCursorX(), this->dm->getCursorY(), x, y);

    // apply window offset
    x += posX;
    y += posY;

    // center hand on top o tile
    x += this->dm->getTileWidth()/2;
    y += this->dm->getTileHeight()/2;

    // draw hand
    this->hand->render(x, y);

    // draw score
    this->scoreboard->setText( "Score: " + std::to_string(this->score) );
    this->scoreboard->render();


    // timer control
    // every second we decrease score by 1
    if (this->currentTime >= 1.0 ) {
        this->score--;
        this->currentTime = this->currentTime - 1;
    }

    this->currentTime += time;

    // repassa o tempo de execucao para a animacao da "hand"
    this->hand->addTime(time);

    // draw fps
    this->fps->tick(time);
    this->fpsText->setText("FPS: " + std::to_string( fps->getFPS() ));
    this->fpsText->render();
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

        // game keybindings
        case GLFW_KEY_SPACE:
            this->dm->changeSelectedTileTo( this->menu->getSelected() );
        break;
        // end game keybindings
    }

}
