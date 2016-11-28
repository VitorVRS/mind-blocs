#ifndef SCREEN_ABSTRACT_SCREEN_HEADER
#define SCREEN_ABSTRACT_SCREEN_HEADER

#include "IScreen.h"

namespace Screen {

class AbstractScreen: public IScreen {

private:
    int width, height;

public:
    void setWidth(int width);
    void setHeight(int height);

    int getWidth();
    int getHeight();

};

};

#endif //SCREEN_ABSTRACT_SCREEN_HEADER
