#ifndef SCREEN_START_HEADER
#define SCREEN_START_HEADER

#include "IScreen.h"

namespace Screen {

class Start: public IScreen {

public:
    void execute() const;
    void keypress(int key, int scancode, int mods) const;

};

}

#endif //SCREEN_START_HEADER
