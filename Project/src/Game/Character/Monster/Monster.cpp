#include "Character/Monster/Monster.h"

Monster::Monster(int dungeonLevel, int playerLevel)
{
	DungeonLevel = dungeonLevel; 
	PlayerLevel = playerLevel;

	if (DungeonLevel > 3) DungeonLevel %= 3;
}

Monster::~Monster()
{

}

void Monster::Magnification()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> RandHealth(20, 30);
	uniform_int_distribution<int> RandDamage(5, 10);

	health = RandHealth(gen) * PlayerLevel * DungeonLevel;
	damage = RandDamage(gen) * PlayerLevel * DungeonLevel;
}

void Monster::Hit(int damage)
{
	currentHealth -= damage;

	if (currentHealth <= 0)
	{
		currentHealth = 0;

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
	cout << name << " : if Player Level = " << PlayerLevel << ", DungeonLevel = " << DungeonLevel << " : " << name << "Health = " << health << ", " << name << "Damage = " << damage << endl;
}