#include "Character/Monster/MonsterHit.h"

MonsterHit::MonsterHit(Player* value)
{
	player = value;
}

MonsterHit::~MonsterHit()
{
	player = nullptr;
	monster = nullptr;
}

void MonsterHit::HitByPlayer(int value, int damage, int randValue)
{
	if (isReflection)
	{
		if (randValue < 50)
		{
			player->Hit(damage);
			return;
		}
	}

	if (monster->GetAvoidRate() < value) monster->SetCurrentHealth(monster->GetCurrentHealth() - damage);
}

void MonsterHit::HitByTick(int damage)
{
	monster->SetCurrentHealth(monster->GetCurrentHealth() - damage);
}
