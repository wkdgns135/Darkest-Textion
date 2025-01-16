#include "IO/Sprite.h"

Image* Sprite::GetImage()
{
	if (animation && animation->isPlay) {
		return animation->GetCurrentImage();
	}
	return image;
}

void Sprite::AddAnimation(const vector<string> &path, const float updateTime)
{
	animation = new Animation(path, width, height, updateTime);
}
