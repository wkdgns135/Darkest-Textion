#include "Goblin.h"

Goblin::Goblin(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	Name = "Goblin";
	Magnification();
	CurrentHealth = Health;
}

Goblin::~Goblin()
{

}

//string Goblin::GetName() const
//{
//	return Name;
//}

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
