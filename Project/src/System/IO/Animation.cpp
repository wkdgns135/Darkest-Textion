#include "IO/Animation.h"

Animation::Animation(const vector<string>& path, const int width, const int height, const float updateTime)
{
	this->updateTime = updateTime;
	currentTime = 0;
	isPlay = false;
	isPlayOnce = false;
	index = 0;
	sheet.resize(path.size());
	for (int i = 0; i < path.size(); i++) {
		sheet[i] = new Image(path[i], width, height);
	}
}

Image* Animation::GetCurrentImage()
{
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

void Animation::UpdateDeltaTime(float dt)
{
	const int size = sheet.size();
	int currentindex = (int)(currentTime / 1000 / updateTime) % size;
	if (index != currentindex)sheet[currentindex]->drawCall = true;
	if (isPlayOnce && currentindex == size - 1) {
		isPlay = false;
		isPlayOnce = false;
		if (complete)complete();
	}
	index = currentindex;
	currentTime += dt;
}
