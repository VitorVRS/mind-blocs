#ifndef SCREEN_ISCREEN_HEADER
#define SCREEN_ISCREEN_HEADER

namespace Screen {

class IScreen {


public:
    virtual void show() = 0;
    virtual void keypress(int key, int scancode, int mods) = 0;
    virtual void click(double x, double y, int mods) = 0;

    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};

};

#endif //SCREEN_ISCREEN_HEADER
