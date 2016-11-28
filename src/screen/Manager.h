#ifndef SCREEN_MANAGER_HEADER
#define SCREEN_MANAGER_HEADER

#include "IScreen.h"

namespace Screen {

class Manager {

private:
    static Manager * instance;
    Screen::IScreen * current;
    Manager() {};
    Manager(Manager const&);
    void operator=(Manager const&);

    int screenWidth, screenHeight;

public:

    static Manager * getInstance();

    enum AVAIL_SCREENS {
        Play
    };

    void change(Manager::AVAIL_SCREENS screen);

    Screen::IScreen * getCurrent();
    void setScreenWidth(int screenWidth);
    void setScreenHeight(int screenHeight);
};

};

#endif //SCREEN_MANAGER_HEADER
