//
// Created by VitorVRS on 9/28/16.
//

#ifndef STAR_EXPLORER_TEXT_H
#define STAR_EXPLORER_TEXT_H

#include <string>
#include <GL/gl.h>
#include <GL/glc.h>

namespace Render {
    class Text {
    private:
        std::string text;
        unsigned int posX;
        unsigned int posY;
    public:
        Text(std::string text, unsigned int x, unsigned int y);
        void setText(std::string text);
        void render();
        void setX(unsigned int x);
        void setY(unsigned int y);
    };
}

#endif //STAR_EXPLORER_TEXT_H
