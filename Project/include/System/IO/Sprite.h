#pragma once
#include <string>
#include "Image.h"
#include "Animation.h"
#include "Vector2d.h"

class Sprite {
private:
	int width;
	int height;
	Image* image;

public:
	Animation* animation;
	Vector2d pos;
	Sprite(Vector2d pos, int width, int height) : pos(pos), width(width), height(height) {
		image = nullptr;
		animation = nullptr;
	}
	Sprite(string path, Vector2d pos, int width, int height) : pos(pos) , width(width), height(height) {
		image = new Image(path, width, height);
		animation = nullptr;
	};

	Image* GetImage(const float dt);
	void AddAnimation(const vector<string> &path, const float updateTime);
};