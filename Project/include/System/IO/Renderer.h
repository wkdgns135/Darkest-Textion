#pragma once
#include <unordered_map>
#include <string>
#include "DesignPattern/Singleton.h"
#include "Global/ProjectEnum.h"
#include "IO/Image.h"
#include "IO/Sprite.h"
#include "Vector2d.h"

using namespace std;

class Renderer {
private:
	const int width = 500, height = 300;
	bool isDraw;
	CHAR_INFO* buffer;
	Image* background;
	vector<Sprite*> drawSprite;

	unordered_map<EAsciiArt, string> asciiArtPath =
	{
		{TitleAsciiArt, "drawable/Title.bmp"},
		{MainAsciiArt, "drawable/Main.bmp" },
		{SelectDungeonAsciiArt, "drawable/SelectDungeon.bmp" },
	};

private:
	void SetConsoleWindowSize(int width, int height);
	void DisableConsoleResize();
	void CenterConsoleWindow();

public:
	Renderer();
	void SetConsoleFontForDraw();
	void SetConsoleFontForText();
	void DrawBackground();
	void DrawImage(Image* image);
	void DrawImage(Image* image, const Vector2d &pos);
	void ClearBuffer();
	void FillBuffer();
	void Render();

	inline void AddBackground(string path) { background = new Image(path, width, height); };
	inline void AddSprite(Sprite* sprite) { drawSprite.push_back(sprite); };
	//HERE : add remove method temporarily
	inline void RemoveSprite() { drawSprite.pop_back(); isDraw = true; };
};