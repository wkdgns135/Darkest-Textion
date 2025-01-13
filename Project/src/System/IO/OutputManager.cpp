// OutputManager.cpp
#include <Windows.h>
#include "IO/OutputManager.h"
#include "IO/Image.h"

using namespace std;
using namespace cimg_library;

OutputManager::OutputManager()
{
    this->width = width;
    this->height = height;

    // 콘솔 창 크기 및 글꼴 크기 설정
    SetConsoleFontForDraw();
    SetConsoleWindowSize(width, height); // 콘솔 창 크기를 300x300으로 설정
    DisableConsoleResize(); // 콘솔 창 크기 변경 비활성화
    CenterConsoleWindow(); // 콘솔 창을 모니터 중앙에 배치

}



void OutputManager::SetConsoleFontForDraw()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 3;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetConsoleWindowSize(width, height); // 콘솔 창 크기를 300x300으로 설정
}

void OutputManager::SetConsoleFontForText()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 18;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetConsoleWindowSize(width / 6, height / 6); // 콘솔 창 크기를 300x300으로 설정
}


void OutputManager::SetConsoleWindowSize(int width, int height) {
    COORD coord;
    coord.X = width;
    coord.Y = height;

    SMALL_RECT rect;
    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = height - 1;
    rect.Right = width - 1;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsole, coord);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void OutputManager::DisableConsoleResize() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_SIZEBOX; // 크기 조정 비활성화
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void OutputManager::CenterConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    RECT rect;
    GetWindowRect(consoleWindow, &rect);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    SetWindowPos(consoleWindow, HWND_TOP, posX, posY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void OutputManager::PrintAsciiArt(const EAsciiArt& asciiArt)
{
    SetConsoleFontForDraw();
    DrawImage(CreateImage(asciiArt));
}

CImg<int> ScaleImage(const CImg<int>& image, int newWidth, int newHeight) {
    return image.get_resize(newWidth, newHeight);
}

Image* OutputManager::CreateImage(const EAsciiArt& asciiArt)
{
    const TCHAR map[] = TEXT(" .,:;ox%#@");
    int mapSize = 10;

    // create image from file
    CImg<int> temp;
    temp.load(asciiArtPath[asciiArt].c_str());

    // 스케일링 적용
    temp = ScaleImage(temp, this->width, this->height);

    int width = temp.width();
    int height = temp.height();

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
        int grayValueWeight = (int)(0.299 * R + 0.587 * G + 0.114 * B);

        // saving píxel values into image information
        grayWeight(x, y, 0, 0) = grayValueWeight;
        mask(x, y, 0, 0) = (R == 255 && G == 0 && B == 255) ? 0 : 1;
    }

    TCHAR* image = new TCHAR[width * height];
    bool* m = new bool[width * height];

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            unsigned char v = grayWeight(w, h, 0, 0);

            image[h * width + w] = map[(v)*mapSize / 256];
            m[h * width + w] = mask(w, h, 0, 0) == 1;
        }
    }

    return new Image(image, m, width, height);
}

void OutputManager::DrawImage(Image* data)
{
    const int width = data->GetWidth();
    const int height = data->GetHeight();
    CHAR_INFO* buffer = new CHAR_INFO[width * height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x;
            int dy = y;

            if (dx < 0 || dx >= width || dy < 0 || dy >= height) {
                continue;
            }

            int dIndex = dy * width + dx;
            buffer[dIndex].Attributes = 7;

            if (!data->GetMask(x, y)) {
                continue;
            }

            buffer[dIndex].Char.UnicodeChar = data->GetPixel(x, y);
        }
    }
    COORD null = { 0, 0 }, size = { width, height };
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), buffer, size, null, &rect);
    delete[] buffer;
}


