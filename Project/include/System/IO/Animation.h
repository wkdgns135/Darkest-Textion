#pragma once
#include <vector>
#include <functional>
#include "Image.h"
#include "Vector2d.h"

class Animation {
private:
	float updateTime;
	vector<Image*> sheet;
	function<void()> complete;
	int index;
public:
	float currentTime;
	bool isPlay;
	bool isPlayOnce;

	Animation(const vector<string> &path, const int width, const int height, const float updateTime);
	Image* GetCurrentImage();
	void PlayLoop();
	void StopLoop();
	void PlayOnce(function<void()>&& Complete = nullptr);
	void UpdateDeltaTime(float dt);
};