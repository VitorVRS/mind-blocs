#include "Animation.h"

using namespace Render;

Image *Animation::getFrame(int index) {
    Image* img = frames.at((unsigned long) index);
    return img;
}

Animation::Animation() {
    frames = std::vector<Image*>();
    frameCount = 0;
}

void Animation::addFrame(Image *image) {
    frames.push_back(image);
    frameCount++;
}

