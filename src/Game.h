#ifndef GAME_HEADER
#define GAME_HEADER

#include <GLFW/glfw3.h>
#include <GL/glc.h>

#include "file/PTMFileReader.h"
#include "common/SpriteLoader.h"
#include "screen/Manager.h"
#include "tiles/Tile.h"
#include "tiles/TileSet.h"
#include "render/Text.h"

class Game {


public:
    Game() {};
    ~Game() {};
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setTitle(char* title);
    void init();

    static const int TILE_WIDTH = 128;

private:
    char* title;
    int window_width;
    int window_height;
    int window_pos_x;
    int window_pos_y;
    void initGLDisplay();
    void initGLC();
    void loadTilesFile();
};


#endif //GAME_HEADER
