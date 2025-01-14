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
			//cout << monster->GetName() << " Hit by Player. But Active Reflection. Player Attack To Player. Damage = " << damage << endl;
			return;
		}
	}

	if (monster->GetAvoidRate() < value)
	{
		monster->SetCurrentHealth(monster->GetCurrentHealth() - damage);
		//cout << monster->GetName() << " Hit by Player. Hit Damage = " << damage << endl;
	}
	else
	{
		//monster->SetCurrentHealth(monster->GetCurrentHealth() - damage * monster->GetDamageRate());
		//cout << monster->GetName() << " Hit by Player. But Monster Avoid. Hit Damage = " << damage * monster->GetDamageRate() << endl;
	}

	//cout << monster->GetName() << " Current Health = " << monster->GetCurrentHealth() << endl;

	if (monster->GetCurrentHealth() <= 0)
	{
		monster->SetCurrentHealth(0);
		//cout << monster->GetName() << " Current Health is zero. Monster Die" << endl;
		monster->Die();
	}
}
