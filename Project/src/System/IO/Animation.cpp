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
	//TODO : �ִϸ��̼� ���� �ð��� ���� �̹��� ������Ʈ
	// currentTime�� 50 ������ ���� ->> 0.05�ʾ� ����
	// 
	const int size = sheet.size();
	float t = currentTime / 1000; // ���� �ð� �ʴ���
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
