#pragma once
#include <string>
#include "Image.h"
#include "Animation.h"
#include "Vector2d.h"

class Sprite {
private:
	Animation* animation;
	int width;
	int height;

public:
	Image* image;
	Vector2d pos;
	Sprite(string path, Vector2d pos, int width, int height) : pos(pos) , width(width), height(height) {
		image = new Image(path, width, height);
		animation = nullptr;
	};

	Image* GetImage(const float dt);
	void AddAnimation(const vector<string> &path, const float updateTime);
};