#include "IO/Sprite.h"


Image* Sprite::GetImage(const float dt)
{
	if (animation && animation->isPlay) {
		animation->currentTime += dt;
		return animation->GetCurrentImage();
	}
	return image;
}

void Sprite::AddAnimation(const vector<string> &path, const float updateTime)
{
	animation = new Animation(path, width, height, updateTime);
}
