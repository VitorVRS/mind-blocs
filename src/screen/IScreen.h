#ifndef SCREEN_ISCREEN_HEADER
#define SCREEN_ISCREEN_HEADER

namespace Screen {

class IScreen {

private:

public:
    virtual void show() const = 0;
    virtual void keypress(int key, int scancode, int mods) const = 0;

};

};

#endif //SCREEN_ISCREEN_HEADER
