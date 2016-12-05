#ifndef SCREEN_GAMEOVER_HEADER
#define SCREEN_GAMEOVER_HEADER

#include <GLFW/glfw3.h>

#include "AbstractScreen.h"
#include "Manager.h"
#include "../render/Text.h"



namespace Screen {

class GameOver: public AbstractScreen {

private:
    Render::Text * message;

public:
    GameOver();
    ~GameOver();
    void show(double time);
    void keypress(int key, int scancode, int mods);
    void click(double x, double y, int mods);

};

}

#endif //SCREEN_GAMEOVER_HEADER
