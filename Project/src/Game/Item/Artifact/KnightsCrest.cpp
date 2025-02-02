﻿#include "Item/Artifact/KnightsCrest.h"
#include "Character/Player/Player.h"

KnightsCrest::KnightsCrest()
{
	name = "KnightsCrest";
	price = 100;
	rank = EArtifactRank::COMMON;
	amount = 10;
	imagePath = "drawable/Item/KnightsCrest.bmp";
}

void KnightsCrest::Attach(Player& player)
{
	player.AddDamage(amount);
	return;
}

void KnightsCrest::Detach(Player& player)
{
	//HERE : player의 데미지 내리기
	player.AddDamage(-amount);
	return;
}