#include "Hand.h"

#include <iostream>
#include <GL/gl.h>

Render::Hand::Hand() {

    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "resources/hand.ptm");
    SpriteLoader loader = SpriteLoader(img);

    this->currentFrame = 0;
    this->animation = loader.getAnimation(8, 1);
}

Render::Hand::~Hand() {
    delete this->animation;
}

void Render::Hand::render(int x, int y) {

    // hand frame need to change
    if (this->elapsedTime >= 0.08) {

        this->elapsedTime = 0;

        if (this->currentFrame == 7) {
            this->currentFrame = 0;
        }
        else {
            this->currentFrame++;
        }

    }

    Image * frame = this->animation->getFrame(this->currentFrame);

    // workaround
    // change hand animation to use textures
    glDisable(GL_TEXTURE_2D);

    glRasterPos2f(x - frame->getWidth()/2, y);
    glDrawPixels(frame->getWidth(), frame->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, frame->getPixels());

    // workaround
    glEnable(GL_TEXTURE_2D);

}

void Render::Hand::addTime(double time) {
    this->elapsedTime += time;
}