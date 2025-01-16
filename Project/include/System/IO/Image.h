#pragma once
#include <string>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

class Image {
private:
    TCHAR* data;
    bool* mask;
    int width;
    int height;
public:
    bool drawCall;
    Image(const string path, int w, int h);
    ~Image();
    inline int GetWidth() const { return this->width; }
    inline int GetHeight() { return this->height; }
    inline TCHAR GetPixel(int x, int y) { return this->data[y * this->width + x]; }
    inline bool GetMask(int x, int y) { return this->mask[y * this->width + x]; }
};