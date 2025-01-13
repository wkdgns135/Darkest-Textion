#include "Item/Artifact/SpeedStone.h"

SpeedStone::SpeedStone()
{
	name = "SpeedStone";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 1;
}

void SpeedStone::Attach(Player& player)
{
	//HERE : player의 이동속도 올려주기
	//player.SetSpeed(player.GetSpeed()+amount);
	return;
}

void SpeedStone::Detach(Player& player)
{
	//HERE : player의 이동속도 내리기
	//player.SetSpeed(player.GetSpeed()-amount);
	return;
}