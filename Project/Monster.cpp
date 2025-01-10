#include "Monster.h"

Monster::Monster(int dungeonLevel, int playerLevel)
{
	DungeonLevel = dungeonLevel; 
	PlayerLevel = playerLevel;

	if (DungeonLevel > 3) DungeonLevel %= 3;
}

Monster::~Monster()
{

}

const string Monster::GetName()
{
	return Name;
}

void Monster::Magnification()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> RandHealth(20, 30);
	uniform_int_distribution<int> RandDamage(5, 10);

	Health = RandHealth(gen) * PlayerLevel * DungeonLevel;
	Damage = RandDamage(gen) * PlayerLevel * DungeonLevel;
}

void Monster::Hit(int damage)
{
	CurrentHealth -= damage;

	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;

		Die();
	}
}

void Monster::Attack()
{
	
}

void Monster::Die()
{
	
}

void Monster::TestPrint()
{
	cout << Name << " : if Player Level = " << PlayerLevel << ", DungeonLevel = " << DungeonLevel << " : Boss Health = " << Health << ", Boss Damage = " << Damage << endl;
}