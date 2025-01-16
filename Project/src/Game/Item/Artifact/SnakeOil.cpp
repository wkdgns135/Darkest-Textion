#include "Item/Artifact/SnakeOil.h"
#include "Character/Player/Player.h"

SnakeOil::SnakeOil()
{
	name = "SnakeOil";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 10;
	imagePath = "drawable/Item/SnakeOil.bmp";
}

void SnakeOil::Attach(Player& player)
{
	player.SetAdditionalStress(player.GetAdditionalStress() + amount);
	return;
}

void SnakeOil::Detach(Player& player)
{
	player.SetAdditionalStress(player.GetAdditionalStress() - amount);
	return;
}