#include "IO/Image.h"
#include <string>

using namespace cimg_library;
using namespace std;

Image::Image(const string path, int width, int height)
{
    this->width = width;
    this->height = height;

    const TCHAR map[] = TEXT(" .,:;∴∵oxwm%#@");
    int mapSize = sizeof(map) / sizeof(map[0]) - 1;

    CImg<int> image;
    image.load(path.c_str());
    image.resize(width, height);

    this->data = new TCHAR[width * height];
    this->mask = new bool[width * height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int R = image(x, y, 0, 0);
            int G = image(x, y, 0, 1);
            int B = image(x, y, 0, 2);
            int grayValueWeight = static_cast<int>(0.299 * R + 0.587 * G + 0.114 * B);
            this->data[y * width + x] = map[(grayValueWeight * mapSize) / 256];
            this->mask[y * width + x] = (R == 255 && G == 255 && B == 255) ? 0 : 1;
        }
    }
}

Image::~Image()
{
    delete[] data;
    delete[] mask;
}


