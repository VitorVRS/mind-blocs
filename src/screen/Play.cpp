#include "Play.h"

#include "GLFW/glfw3.h"
#include <iostream>
#include <iomanip>

Screen::Play::Play() {

    this->score = 1;

    this->started = false;
    this->startTime = 0;

    this->dm = new Render::Diamond(Game::TILE_WIDTH);

    this->level = nullptr;
    this->levelCount = 0;
    this->loader = new LevelLoader(0);

    this->nextLevel();

    this->hand = new Render::Hand();
    this->menu = new Render::Menu();

    this->scoreboard = new Render::Text("", 600, 580);
    this->timerText = new Render::Text("", 600, 540);
    this->levelText = new Render::Text("Level:" + std::to_string(this->levelCount), 600, 500);

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
    delete this->timerText;
    delete this->levelText;
}

void Screen::Play::show(double time) {

    if (score <= 0) {
        Screen::Manager::getInstance()->change(Screen::Manager::GameOver);
    }

    // valor utilizado para somar ao x e y
    // para centralizar o diamond
    int posX = this->getWidth()/2 - this->dm->getTileWidth() / 2;
    int posY = this->getHeight()/2 - this->dm->getHeight() / 2;

    // draw diamond
    this->dm->render(posX, posY);

    if (this->started) {

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
        this->timerText->setText("Remaining: " + std::to_string(this->remainingTime));
        this->timerText->render();
        this->levelText->setText("Level: " + std::to_string(this->levelCount));
        this->levelText->render();
    }

    // timer control
    // every second we decrease score by 1
    if (this->started && this->currentTime >= 1.0 ) {
        this->remainingTime--;
        this->currentTime = this->currentTime - 1;
        if (this->remainingTime <= 0)
            Screen::Manager::getInstance()->change(Screen::Manager::GameOver);
    }

    if (!this->started && this->startTime >= 5) {
        this->started = true;
        this->resetMap();
    }

    if (!this->started) {
        this->startTime += time;
    }

    if (this->started) {
        this->currentTime += time;
    }

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

    if (!this->started) {
        return;
    }

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

        case GLFW_KEY_ENTER:

            if ( this->level->validate(this->dm->getTileMap()) ) {
                this->nextLevel();
                this->levelText->setText("Level: " + std::to_string(this->levelCount));
            } else {
                Screen::Manager::getInstance()->change(Screen::Manager::GameOver);
            }

        break;
        // end game keybindings
    }

}

void Screen::Play::nextLevel() {
    if (this->levelCount >= 1)
        this->score = this->levelCount * this->remainingTime;

    if (this->level != nullptr) {
        delete this->level;
    }

    this->started = false;
    this->startTime = 0;

    Tiles::TileMap * map = new Tiles::TileMap();

    this->loader->incrementLevel();
    this->levelCount++;

    if ( !this->loader->setCurrentLevel(map) ) {
        Screen::Manager::getInstance()->change(Screen::Manager::GameOver);
    }

    this->remainingTime = map->minimumTime;
    this->level = new Level(map);
    this->dm->setTileMap(map);
}

void Screen::Play::resetMap() {

    int cols = this->level->getTileMap()->getCols();
    int rows = this->level->getTileMap()->getRows();

    Tiles::TileMap * tileMap = new Tiles::TileMap();
    tileMap->cols = cols;
    tileMap->rows = rows;
    tileMap->tiles = new unsigned int[tileMap->cols * tileMap->rows];

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            tileMap->tiles[i + j * cols] = 0;
        }
    }

    this->dm->setTileMap(tileMap);
}
