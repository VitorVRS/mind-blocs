#ifndef GAME_HEADER
#define GAME_HEADER

#include <GLFW/glfw3.h>

#include "screen/Manager.h"

class Game {

public:
    Game() {};
    ~Game() {};
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setTitle(char* title);
    void init();
private:
    char* title;
    int window_width;
    int window_height;
    int window_pos_x;
    int window_pos_y;
    void initGLDisplay();
};


#endif //GAME_HEADER
