#include "Item/Artifact/KnightsCrest.h"
#include "Character/Player/Player.h"

KnightsCrest::KnightsCrest()
{
	name = "KnightsCrest";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 10;
}

void KnightsCrest::Attach(Player& player)
{
	player.AddDamage(amount);
	return;
}

void KnightsCrest::Detach(Player& player)
{
	//HERE : player의 데미지 내리기
	return;
}