#include "Character/Monster/Orc.h"

Orc::Orc(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	name = "Orc";
	Magnification();
	currentHealth = health;
}

Orc::~Orc()
{

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
