#include "Item/Artifact/ExpStone.h"
#include "Character/Player/Player.h"

ExpStone::ExpStone()
{
	name = "ExpStone";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 10;
	imagePath = "drawable/Item/ExpStone.bmp";
}

void ExpStone::Attach(Player& player)
{
	//HERE : player의 획득 경험치 올려주기
	player.SetAdditionExp(player.GetAdditionExp() + amount);
	return;
}

void ExpStone::Detach(Player& player)
{
	//HERE : player의 획득 경험치 내리기
	player.SetAdditionExp(player.GetAdditionExp() - amount);
	return;
}