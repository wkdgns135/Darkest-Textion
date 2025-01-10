#include "Character/Monster/Goblin.h"

Goblin::Goblin(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	name = "Goblin";
	Magnification();
	currentHealth = health;
}

Goblin::~Goblin()
{

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
