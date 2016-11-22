//
// Created by fredrb on 9/24/16.
//

#include "SpriteLoader.h"
#include "../file/IFileReader.h"

Render::Image *SpriteLoader::getImage() {
    Render::Image* image = new Render::Image(this->fileImage.width, this->fileImage.height);
    for (int i = 0; i < this->fileImage.pixels.size(); i++) {
        File::t_image_pixel p = this->fileImage.pixels.at((unsigned long) i);
        image->setPixel(p.color.alpha, p.color.r, p.color.g, p.color.b, p.x, p.y);
    }

    return image;
}

Render::Animation *SpriteLoader::getAnimation(int rows, int columns) {
    Render::Image* origin = this->getImage();
    int spriteX = origin->getWidth() / rows;
    int spriteY = origin->getHeight() / columns;

    Render::Animation* animation = new Render::Animation();
    for (int y = 0; y < columns; y++) {
        for (int x = 0; x < rows; x++) {
            Render::Image* subImg = new Render::Image(spriteX, spriteY);
            origin->subImage(subImg, x * spriteX, y * spriteY);
            animation->addFrame(subImg);
        }
    }

    return animation;
}

