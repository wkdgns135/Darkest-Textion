#pragma once
#include <string>
#include "Image.h"
#include "Vector2d.h"

class Sprite {
public:
	Image* image;
	Vector2d pos;
	Sprite(string path, Vector2d pos, int width, int height) : pos(pos) {
		image = new Image(path, width, height);
	};
};