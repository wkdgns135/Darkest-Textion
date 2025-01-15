#pragma once
#include <vector>
#include "Image.h"
#include "Vector2d.h"

class Animation {
private:
	float updateTime;
	vector<Image*> sheet;

public:
	float currentTime;
	bool isPlay;

	Animation(const vector<string> &path, const int width, const int height, const float updateTime);
	Image* GetCurrentImage();
	void PlayLoop();
	void StopLoop();
	void PlayOnce();
};