#include "IO/Animation.h"

Animation::Animation(const vector<string>& path, const int width, const int height, const float updateTime)
{
	this->updateTime = updateTime;
	currentTime = 0;
	isPlay = false;
	isPlayOnce = false;

	sheet.resize(path.size());
	for (int i = 0; i < path.size(); i++) {
		sheet[i] = new Image(path[i], width, height);
	}
}

Image* Animation::GetCurrentImage()
{
	const int size = sheet.size();
	float t = currentTime / 1000; // 현재 시간 초단위
	int index = (int)(t / updateTime) % size;

	if (isPlayOnce && index == size - 1) {
		isPlay = false;
		isPlayOnce = false;
		if (complete)complete();
	}
	return sheet[index];
}

void Animation::PlayLoop()
{
	isPlay = true;
}

void Animation::StopLoop()
{
	currentTime = 0;
	isPlay = true;
}

void Animation::PlayOnce(function<void()>&& Complete)
{
	complete = move(Complete);
	currentTime = 0;
	isPlayOnce = true;
	isPlay = true;
}
