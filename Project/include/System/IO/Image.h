#pragma once
//#define cimg_use_jpeg
#include "CImg.h"
using namespace cimg_library;

class Image {
private:
    TCHAR* image;
    bool* mask;
    int width;
    int height;

public:
    Image(TCHAR* image, bool* mask, int width, int height) : image(image), mask(mask), width(width), height(height) {};
    inline int GetWidth() { return this->width; }
    inline int GetHeight() { return this->height; }
    inline TCHAR GetPixel(int x, int y) { return this->image[y * this->width + x]; }
    inline bool GetMask(int x, int y) { return this->mask[y * this->width + x]; }
};