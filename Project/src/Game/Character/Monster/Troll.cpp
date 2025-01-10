#include "Character/Monster/Troll.h"

Troll::Troll(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	name = "Troll";
	Magnification();
	currentHealth = health;
}

Troll::~Troll()
{

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
