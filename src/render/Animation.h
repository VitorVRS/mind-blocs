#ifndef POINT_READER_ANIMATION_H
#define POINT_READER_ANIMATION_H


#include <vector>
#include "Image.h"

namespace Render {
    class Animation {
    public:
        Animation();
        ~Animation() {};
        void addFrame(Image *image);
        Image* getFrame(int index);
    private:
        int frameCount;
        std::vector<Image*> frames;
        // Image** frames;
    };
}

#endif //POINT_READER_ANIMATION_H
