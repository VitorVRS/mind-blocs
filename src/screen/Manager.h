#ifndef SCREEN_MANAGER_HEADER
#define SCREEN_MANAGER_HEADER

namespace Screen {

class Manager {

private:
    static Manager * instance;
    // Screen::Screen * current;
    Manager() {};
    Manager(Manager const&);
    void operator=(Manager const&);

public:

    static Manager * getInstance();

    enum AVAIL_SCREENS {
        Start
    };

    void change(Manager::AVAIL_SCREENS screen);
};

};

#endif //SCREEN_MANAGER_HEADER
