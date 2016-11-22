//
// Created by fredrb on 9/24/16.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "PTMFileReader.h"

using namespace File;

t_image PTMFileReader::loadImage(char *filepath) {
    std::ifstream file = std::ifstream(filepath);

    if (file.is_open()) {
        return this->readFile(file);
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    return t_image();
}

t_image PTMFileReader::readFile(std::ifstream& ifstream) {
    if (checkFileType(ifstream, "P7")) {
        t_image_size size = getImageSize(ifstream);
        std::cout << "Width:\t" << size.width << std::endl;
        std::cout << "Height:\t" << size.height << std::endl;
        int maxValue = getMaxValue(ifstream);
        return getImageFromFile(ifstream, size, maxValue);
    } else {
        std::cout << "Wrong file type" << std::endl;
    }
    return t_image();
}

bool PTMFileReader::checkFileType(std::ifstream& ifstream, const char *type) {
    std::string line;
    getline(ifstream, line);
    return line == type;
}

t_image_size PTMFileReader::getImageSize(std::ifstream& ifstream) {
    std::string line;
    getline(ifstream, line);

    std::stringstream stream(line);
    t_image_size img_size;

    img_size.width = getIntValue(stream, ' ');
    img_size.height = getIntValue(stream, ' ');

    return img_size;
}

int PTMFileReader::getIntValue(std::stringstream& stream, char delimiter) {
    std::string value;
    getline(stream, value, ' ');
    return std::stoi(value);
}

int PTMFileReader::getMaxValue(std::ifstream& file) {
    std::string line;
    getline(file, line);
    return std::stoi(line);
}

t_image PTMFileReader::getImageFromFile(std::ifstream& openfile, t_image_size size, int value) {
    t_image img;
    img.pixels = std::vector<t_image_pixel>();
    img.height = size.height;
    img.width = size.width;

    for (int y = size.height - 1; y >= 0; y--) {
        for (int x = 0; x < size.width; x++) {
            t_pixel_color pixelColor = readOnePixelFrom(openfile);
            t_image_pixel pixel;

            pixel.color = pixelColor;
            pixel.x = x;
            pixel.y = y;
            img.pixels.push_back(pixel);
        }
    }
    return img;
}

t_pixel_color PTMFileReader::readOnePixelFrom(std::ifstream& file) {
    t_pixel_color pixel;
    std::string byte;
    getline(file, byte, ' ');
    pixel.alpha = std::stoi(byte);

    getline(file, byte, ' ');
    pixel.r = std::stoi(byte);

    getline(file, byte, ' ');
    pixel.g = std::stoi(byte);

    getline(file, byte, ' ');
    pixel.b = std::stoi(byte);

    return pixel;
}
