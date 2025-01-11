#include "Character/Monster/Troll.h"

Troll::Troll(int dungeonLevel) : Monster(dungeonLevel)
{
	name = "Troll";
	Rank = 1;
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
}

Troll::~Troll()
{
	__super::~Monster();
}

Item* Troll::DropItem()
{
	return nullptr;
}

void Troll::Hit(int damage)
{
	__super::Hit(damage);
}

void Troll::Attack()
{
	__super::Attack();
}

void Troll::Die()
{
	__super::Die();
}
