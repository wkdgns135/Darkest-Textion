#include "Character/Monster/Orc.h"

Orc::Orc(int dungeonLevel) : Monster(dungeonLevel)
{
	name = "Orc";
	Rank = 0;
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
}

Orc::~Orc()
{
	__super::~Monster();
}

Item* Orc::DropItem()
{
	return nullptr;
}

void Orc::Hit(int damage)
{
	__super::Hit(damage);
}

void Orc::Attack()
{
	__super::Attack();
}

void Orc::Die()
{
	__super::Die();
}
