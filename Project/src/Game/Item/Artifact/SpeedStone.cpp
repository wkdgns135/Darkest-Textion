#include "Item/Artifact/SpeedStone.h"

SpeedStone::SpeedStone()
{
	name = "SpeedStone";
	amount = 1.f;
	rank = EArtifactRank::COMMON;
	price = 100.f;
}

string SpeedStone::GetName() const
{
	return name;
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