#include <iostream>
#include "Manager.h"
#include "Play.h"

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

        case Screen::Manager::Play:
            printf("%s\n", "Switching to Start");
            this->current = new Screen::Play();
        break;

    }

}

Screen::IScreen * Screen::Manager::getCurrent() {
    return this->current;
}
