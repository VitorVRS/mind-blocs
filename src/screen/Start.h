#ifndef SCREEN_START_HEADER
#define SCREEN_START_HEADER

#include <GLFW/glfw3.h>

#include "AbstractScreen.h"
#include "Manager.h"
#include "../render/Text.h"

namespace Screen {

class Start: public AbstractScreen {

private:
    Render::Text * message;

public:
    Start();
    ~Start();
    void show(double time);
    void keypress(int key, int scancode, int mods);
    void click(double x, double y, int mods);

};

}

#endif // SCREEN_START_HEADER