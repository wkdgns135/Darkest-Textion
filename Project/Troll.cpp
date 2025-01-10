#include "Troll.h"

Troll::Troll(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	Name = "Troll";
	Magnification();
	CurrentHealth = Health;
}

Troll::~Troll()
{

}

//string Troll::GetName() const
//{
//	return Name;
//}

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
