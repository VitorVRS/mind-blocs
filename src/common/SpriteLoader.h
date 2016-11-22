#ifndef STAR_EXPLORER_SPRITELOADER_H
#define STAR_EXPLORER_SPRITELOADER_H

#include "../file/IFileReader.h"
#include "../render/Image.h"
#include "../render/Animation.h"

class SpriteLoader {
public:
    SpriteLoader(File::t_image fileImage) { this->fileImage = fileImage; };
    Render::Image* getImage();
    Render::Animation* getAnimation(int rows, int columns);

private:
    File::t_image fileImage;
};


#endif //STAR_EXPLORER_SPRITELOADER_H
