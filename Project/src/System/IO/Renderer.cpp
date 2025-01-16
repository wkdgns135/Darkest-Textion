#include <Windows.h>
#include "IO/Renderer.h"

using namespace cimg_library;

Renderer::Renderer()
{
    // 콘솔 창 크기 및 글꼴 크기 설정
    SetConsoleFontForDraw();
    SetConsoleWindowSize(width, height); // 콘솔 창 크기를 300x300으로 설정
    DisableConsoleResize(); // 콘솔 창 크기 변경 비활성화
    CenterConsoleWindow(); // 콘솔 창을 모니터 중앙에 배치

    buffer = new CHAR_INFO[this->width * height];
    ClearBuffer();

    isDraw = true;
}

Renderer::~Renderer()
{
    delete buffer;
    delete background;
}

void Renderer::SetConsoleFontForDraw()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 3;
    cfi.dwFontSize.Y = 3;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetConsoleWindowSize(width, height);
}

void Renderer::SetConsoleFontForText()
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
    SetConsoleWindowSize(width / 6, height / 6);
}


void Renderer::SetConsoleWindowSize(int width, int height) {
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

void Renderer::DisableConsoleResize() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_SIZEBOX; // 크기 조정 비활성화
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Renderer::CenterConsoleWindow() {
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

void Renderer::DrawBackground()
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x < 0 || x >= width || y < 0 || y >= height) {
                continue;
            }
            int dIndex = y * width + x;
            if (!background->GetMask(x, y)) {
                continue;
            }
            buffer[dIndex].Char.UnicodeChar = background->GetPixel(x, y);
        }
    }
}

void Renderer::DrawImage(Image* image)
{
    DrawImage(image, { 0, 0 });
}

void Renderer::DrawImage(Image* image, const Vector2d &pos)
{
    if (image == nullptr)return;
    const int left = pos.x;
    const int top = pos.y;
    const int width = image->GetWidth();
    const int height = image->GetHeight();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x + left;
            int dy = y + top;

            if (dx < 0 || dx >= this->width || dy < 0 || dy >= this->height) {
                continue;
            }

            //int sIndex = y * width + x;
            int dIndex = dy * this->width + dx;

            if (!image->GetMask(x, y)) {
                continue;
            }
            buffer[dIndex].Char.UnicodeChar = image->GetPixel(x, y);
        }
    }
}

void Renderer::DrawNumber(int number, const Vector2d& pos, int width, int height)
{
    string str = to_string(number);
    vector<Sprite*> sprites;
    for (int i = 0; i < str.size(); i++) {
        string path = "drawable/Number/";
        path += str[i];
        path += ".bmp";
        int x = pos.x - (width / 5) + (width / 2) * i;
        int y = pos.y;
        Sprite* sprite = new Sprite(path, { x, y }, width, height);
        drawSprite.push_back(sprite);
    }
}

void Renderer::ClearBuffer()
{
    for (int i = 0; i < width * height; i++) {
        buffer[i].Char.UnicodeChar = ' ';
        buffer[i].Attributes = 7;
    }
}

void Renderer::FillBuffer(float deltaTime)
{
    if (background) {
        DrawBackground();
    }

    for (Sprite* sprite : fixSprite) {
        DrawImage(sprite->GetImage(deltaTime), sprite->pos);
    }

    for (Sprite* sprite : drawSprite) {
        DrawImage(sprite->GetImage(deltaTime), sprite->pos);
    }
}

void Renderer::Render()
{
    if (!isDraw)return;
    system("cls");

    COORD null = { 0, 0 }, size = { width, height };
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), buffer, size, null, &rect);
    isDraw = false;
}
