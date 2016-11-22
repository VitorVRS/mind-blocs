//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_PTMFILEREADER_H
#define STAR_EXPLORER_PTMFILEREADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include "IFileReader.h"

namespace File {

    typedef struct {
        int width;
        int height;
    } t_image_size;

    class PTMFileReader : public IFileReader {
    public:
        virtual t_image loadImage(char *filepath) override ;
    private:
        t_image readFile(std::ifstream& ifstream);
        bool checkFileType(std::ifstream& ifstream, const char type[3]);
        t_image_size getImageSize(std::ifstream& ifstream);
        int getIntValue(std::stringstream& stream, char delimiter);
        int getMaxValue(std::ifstream& file);
        t_image getImageFromFile(std::ifstream& openfile, t_image_size size, int value);
        t_pixel_color readOnePixelFrom(std::ifstream& file);
    };
}




#endif //STAR_EXPLORER_PTMFILEREADER_H
