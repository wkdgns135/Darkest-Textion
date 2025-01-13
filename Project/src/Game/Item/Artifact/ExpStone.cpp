#include "Item/Artifact/ExpStone.h"
#include "Character/Player/Player.h"

ExpStone::ExpStone()
{
	name = "ExpStone";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 1;
}

void ExpStone::Attach(Player& player)
{
	//HERE : player의 획득 경험치 올려주기
	return;
}

void ExpStone::Detach(Player& player)
{
	//HERE : player의 획득 경험치 내리기
	return;
}