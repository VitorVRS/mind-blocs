#include <iostream>
#include "Manager.h"

Screen::Manager * Screen::Manager::instance = nullptr;

Screen::Manager * Screen::Manager::getInstance() {

    if (instance == nullptr) {
        instance = new Screen::Manager();
    }

    return instance;
};

void Screen::Manager::change(Screen::Manager::AVAIL_SCREENS screen) {

    switch (screen) {

        case Screen::Manager::Start:
            printf("%s\n", "Switching to Start");
        break;

    }

}