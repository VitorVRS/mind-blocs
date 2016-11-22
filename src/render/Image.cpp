#include "Image.h"

using namespace Render;

Image::Image(int w, int h) {
    width = w; height = h;
    pixels = new int[w*h];
}

Image::~Image() {
    delete pixels;
}

int Image::getPixel(int x, int y) {
    return pixels[x+y*width];
}

int Image::packageBit(int a, int r, int g, int b) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

void Image::setPixel(int alpha, int r, int g, int b, int x, int y) {
    if (isValidPixel(x, y))
        pixels[x+y*width] = packageBit(alpha, r, g, b);
}

void Image::setPixel(int pixel, int x, int y) {
    pixels[x+y*width] = pixel;
}

void Image::plot(Image *image, int sx, int sy) {
    int h = image->getHeight();
    int w = image->getWidth();
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int pixel = image->getPixel(x, y);
            int alpha = ((pixel >> 24) & 0xff);
            if (alpha == 255) {
                if (isValidPixel(sx + x, sy + y)) {
                    pixels[(sx + x) + (sy + y) * width] = pixel;
                    //pixels[(sx + x) + (sy + y) * width] = packageBit(alpha, ((pixel >> 16) & 0xff), ((pixel >> 8) & 0xff), ((pixel) & 0xff));

                }
            }
        }
    }
}

t_image_pixel Image::unpackagePixel(int pixel) {
    t_image_pixel unpackaged;
    unpackaged.alpha = (pixel >> 24) & 0xff;
    unpackaged.r     = (pixel >> 16) & 0xff;
    unpackaged.g     = (pixel >> 8)  & 0xff;
    unpackaged.b     = (pixel)       & 0xff;

    return unpackaged;
}

int Image::unpackageAlpha(int pixel) {
    return (pixel >> 24) & 0xff;
}

void Image::subImage(Image *dest, int sx, int sy) {
    int h = dest->getHeight();
    int w = dest->getWidth();
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            copyPixel(dest, sx, sy, x, y);
        }
    }
}

bool Image::isValidPixel(int x, int y) {
    return this->getWidth() > x && this->getHeight() > y;
}

void Image::copyPixel(Image* dest, int sx, int sy, int x, int y) {
    int pixel = this->pixels[(sx+x)+ (sy+y)*width];
    dest->setPixel(pixel, x, y);
}
