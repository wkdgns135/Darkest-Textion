#include "Orc.h"

Orc::Orc(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	Name = "Orc";
	Magnification();
	CurrentHealth = Health;
}

Orc::~Orc()
{

}

//string Orc::GetName() const
//{
//	return Name;
//}

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
