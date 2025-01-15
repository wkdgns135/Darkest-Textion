#include "Item/Artifact/SnakeOil.h"
#include "Character/Player/Player.h"

SnakeOil::SnakeOil()
{
	name = "SnakeOil";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 1;
	imagePath = "drawable/Item/SnakeOil.bmp";
}

void SnakeOil::Attach(Player& player)
{
	//HERE : player의 피격시 스트레스 감소
	return;
}

void SnakeOil::Detach(Player& player)
{
	//HERE : player의 피격시 스트레스 증가
	return;
}