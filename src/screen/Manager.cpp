#include <iostream>
#include "Manager.h"
#include "Start.h"
#include "Play.h"
#include "GameOver.h"

Screen::Manager * Screen::Manager::instance = nullptr;

Screen::Manager * Screen::Manager::getInstance() {

    if (instance == nullptr) {
        instance = new Screen::Manager();
    }

    return instance;
};

void Screen::Manager::change(Screen::Manager::AVAIL_SCREENS screen) {

  if (this->current == nullptr) {
        delete this->current;
    }

    switch (screen) {

        case Screen::Manager::Start:
            this->current = new Screen::Start();
        break;

        case Screen::Manager::Play:
            printf("%s\n", "Switching to Start");
            this->current = new Screen::Play();
            this->current->setWidth(this->screenWidth);
            this->current->setHeight(this->screenHeight);
        break;

        case Screen::Manager::GameOver:
            this->current = new Screen::GameOver();
        break;

    }

}

Screen::IScreen * Screen::Manager::getCurrent() {
    return this->current;
}

void Screen::Manager::setScreenWidth(int screenWidth) {
    this->screenWidth = screenWidth;
}

void Screen::Manager::setScreenHeight(int screenHeight) {
    this->screenHeight = screenHeight;
}
