#pragma once
#include <unordered_map>
#include <string>
#include "DesignPattern/Singleton.h"
#include "Global/ProjectEnum.h"
using namespace std;

class Image;

class OutputManager : public Singleton<OutputManager>{
private:
	int width = 500, height = 300;

	unordered_map<EAsciiArt, string> asciiArtPath = 
	{
		{TitleAsciiArt, "drawable/Title.bmp"},
		{MainAsciiArt, "drawable/Main.bmp" },
		{SelectDungeonAsciiArt, "drawable/SelectDungeon.bmp" },
	};

private :
	Image* CreateImage(const EAsciiArt& asciiArt);
	void DrawImage(Image* data);
	void SetConsoleWindowSize(int width, int height);
	void DisableConsoleResize();
	void CenterConsoleWindow();

public:
	OutputManager();
	void SetConsoleFontForDraw();
	void SetConsoleFontForText();
	void PrintAsciiArt(const EAsciiArt &asciiArt);
};