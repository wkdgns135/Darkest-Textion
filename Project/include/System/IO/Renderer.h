#pragma once
#include <string>
#include "IO/Sprite.h"
using namespace std;

class Renderer {
private:
	const int width = 500, height = 300;
	bool isDraw;
	CHAR_INFO* buffer;
	Image* background;
	vector<Sprite*> fixSprite;
	vector<Sprite*> drawSprite;

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
	void DrawNumber(int number, const Vector2d &pos, int width, int height);
	void ClearBuffer();
	void FillBuffer(float deltaTime);
	void Render();

	inline void AddBackground(string path) { background = new Image(path, width, height); };
	inline void AddSprite(Sprite* sprite) { drawSprite.push_back(sprite); }; // 캐릭터나 이펙트와 같이 동적인 스프라이트를 추가합니다.
	inline void AddFixSprite(Sprite* sprite) { fixSprite.push_back(sprite); }; // UI와 같이 정적인 스프라이트를 추가합니다.
	inline void ClearSprite() { drawSprite.clear(); };
};