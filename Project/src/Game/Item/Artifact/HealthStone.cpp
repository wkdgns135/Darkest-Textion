﻿#include "Item/Artifact/HealthStone.h"
#include "Character/Player/Player.h"

HealthStone::HealthStone()
{
	name = "HealthStone";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 1;
}

void HealthStone::Attach(Player& player)
{
	//HERE : player의 최대체력 올려주기
	cout << "Amount is " << amount << '\n';
	return;
}

void HealthStone::Detach(Player& player)
{
	//HERE : player의 최대체력 내리기
	return;
}