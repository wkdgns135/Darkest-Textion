#include "IO/Image.h"
#include <string>

using namespace cimg_library;
using namespace std;

Image::Image(string path, int width, int height)
{
    this->width = width;
    this->height = height;

    const TCHAR map[] = TEXT(" .,:;ox%#@");
    int mapSize = 10;

    // create image from file
    CImg<int> temp;
    temp.load(path.c_str());

    // 스케일링 적용
    temp = temp.get_resize(width, height);

    CImg<int> grayWeight(width, height, 1, 1, 0),
        imgR(width, height, 1, 3, 0),
        imgG(width, height, 1, 3, 0),
        imgB(width, height, 1, 3, 0);

    CImg<int> mask(width, height, 1, 1, 0);

    // for all pixels x,y in image
    cimg_forXY(temp, x, y) {
        imgR(x, y, 0, 0) = temp(x, y, 0, 0),    // Red component of image sent to imgR
            imgG(x, y, 0, 1) = temp(x, y, 0, 1),    // Green component of image sent to imgG
            imgB(x, y, 0, 2) = temp(x, y, 0, 2);    // Blue component of image sent to imgB

        // Separation of channels
        int R = (int)temp(x, y, 0, 0);
        int G = (int)temp(x, y, 0, 1);
        int B = (int)temp(x, y, 0, 2);

        // Real weighted addition of channels for gray
        int grayValueWeight = (int)(0.4 * R + 0.4 * G + 0.2 * B);

        // saving píxel values into image information
        grayWeight(x, y, 0, 0) = grayValueWeight;
        mask(x, y, 0, 0) = (R == 255 && G == 0 && B == 255) ? 0 : 1;
    }

    this->data = new TCHAR[width * height];
    this->mask = new bool[width * height];

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            unsigned char v = grayWeight(w, h, 0, 0);

            this->data[h * width + w] = map[(v)*mapSize / 256];
            this->mask[h * width + w] = mask(w, h, 0, 0) == 1;
        }
    }
}