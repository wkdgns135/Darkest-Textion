#include "IO/Animation.h"

Animation::Animation(const vector<string>& path, const int width, const int height, const float updateTime)
{
	this->updateTime = updateTime;
	currentTime = 0;
	isPlay = true;

	sheet.resize(path.size());
	for (int i = 0; i < path.size(); i++) {
		sheet[i] = new Image(path[i], width, height);
	}
}

Image* Animation::GetCurrentImage()
{
	//TODO : 애니메이션 현재 시간에 따른 이미지 업데이트
	// currentTime은 50 단위로 증가 ->> 0.05초씩 증가
	// 
	const int size = sheet.size();
	float t = currentTime / 1000; // 현재 시간 초단위
	int index = (int)(t / updateTime) % size;
	return sheet[index];
}

void Animation::PlayLoop()
{

}

void Animation::StopLoop()
{

}

void Animation::PlayOnce()
{

}
