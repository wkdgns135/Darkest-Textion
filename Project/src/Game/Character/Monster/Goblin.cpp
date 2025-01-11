#include "Character/Monster/Goblin.h"

Goblin::Goblin(int dungeonLevel) : Monster(dungeonLevel)
{
	name = "Goblin";
	Rank = 0;
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
}

Goblin::~Goblin()
{
	__super::~Monster();
}

Item* Goblin::DropItem()
{
	return nullptr;
}

void Goblin::Hit(int damage)
{
	__super::Hit(damage);
}

void Goblin::Attack()
{
	__super::Attack();
}

void Goblin::Die()
{
	__super::Die();
}
