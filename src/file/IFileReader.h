//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_IFILEREADER_H
#define STAR_EXPLORER_IFILEREADER_H

#include <vector>

namespace File {

    typedef struct {
        int r;
        int g;
        int b;
        int alpha;
    } t_pixel_color;

    typedef struct {
        int x;
        int y;
        t_pixel_color color;
    } t_image_pixel;

    typedef struct {
        int height;
        int width;
        std::vector<t_image_pixel> pixels;
    } t_image;

    class IFileReader {
    public:
        IFileReader() {};
        virtual t_image loadImage(char* filepath) = 0;
    };
}



#endif //STAR_EXPLORER_IFILEREADER_H
