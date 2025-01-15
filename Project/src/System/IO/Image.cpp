#include "IO/Image.h"
#include <string>

using namespace cimg_library;
using namespace std;

Image::Image(const string path, int width, int height)
{
    this->width = width;
    this->height = height;

    const TCHAR map[] = TEXT(" .,:;ox%#@");
    int mapSize = sizeof(map) / sizeof(map[0]) - 1;

    // create image from file
    CImg<int> temp;
    temp.load(path.c_str());

    // 스케일링 적용
    temp.resize(width, height);

    CImg<int> grayWeight(width, height, 1, 1, 0);
    CImg<int> mask(width, height, 1, 1, 0);

    // for all pixels x,y in image
    cimg_forXY(temp, x, y) {
        int R = temp(x, y, 0, 0);
        int G = temp(x, y, 0, 1);
        int B = temp(x, y, 0, 2);

        // Real weighted addition of channels for gray
        int grayValueWeight = static_cast<int>(0.4 * R + 0.4 * G + 0.2 * B);

        // saving pixel values into image information
        grayWeight(x, y) = grayValueWeight;
        mask(x, y) = (R == 255 && G == 255 && B == 255) ? 0 : 1;
    }

    this->data = new TCHAR[width * height];
    this->mask = new bool[width * height];

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            unsigned char v = grayWeight(w, h);

            this->data[h * width + w] = map[(v * mapSize) / 256];
            this->mask[h * width + w] = mask(w, h) == 1;
        }
    }
}

Image::~Image()
{
    delete[] data;
    delete[] mask;
}


