#include "Character/Monster/Monster.h"

Monster::Monster(int dungeonLevel)
{
	DungeonLevel = dungeonLevel; 
	APlayer = GameManager::GetInstance().GetPlayer();
	PlayerLevel = APlayer->GetLevel();
	if (DungeonLevel > 3) DungeonLevel %= 3;
}

Monster::~Monster()
{
	APlayer == nullptr;
}

void Monster::Magnification()
{
	health = GetRandomValue(20, 30) * PlayerLevel * DungeonLevel;
	damage = GetRandomValue(5, 10) * PlayerLevel * DungeonLevel;
}

int Monster::GetRandomValue(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> RandomValue(min, max);

	return RandomValue(gen);
}

void Monster::InitializeByDungeonLevel()
{
	if (Rank == 0)
	{
		MinDropValue = 0;
		ArtifactRate = 5;
		MaxItemRank = 71;
		MaxItemCount = 1;
		HitRate = 80;
		AvoidRate = 5;
	}
	else if (Rank == 1)
	{
		MinDropValue = 25;
		ArtifactRate = 10;
		MaxItemRank = 95;
		MaxItemCount = 2;
		HitRate = 90;
		AvoidRate = 10;
	}
	else
	{
		MinDropValue = 50;
		ArtifactRate = 20;
		MaxItemRank = 100;
		MaxItemCount = 4;
		HitRate = 99;
		AvoidRate = 20;
	}
}

Item* Monster::DropItem()
{
	if (ArtifactRate >= GetRandomValue(0, 100))
	{
		int ItemRankValue = GetRandomValue(0, MaxItemRank);

		if (ItemRankValue <= 40)
		{
			//return COMMON
		}
		else if (ItemRankValue <= 70)
		{
			//return UNCOMMON
		}
		else if (ItemRankValue <= 85)
		{
			//return RARE
		}
		else if (ItemRankValue <= 95)
		{
			//return VERY_RARE
		}
		else if (ItemRankValue <= 99)
		{
			//return TROPHY
		}
		else
		{
			//return ANCESTAL
		}
	}

	int RandomConsumableValue = GetRandomValue(0, 100);

	if (RandomConsumableValue <= 20) {} //return 0 of Consumable Item List
	else if (RandomConsumableValue <= 40) {} //return 1 of Consumable Item List
	else if (RandomConsumableValue <= 60) {} //return 2 of Consumable Item List
	else if (RandomConsumableValue <= 80) {} //return 3 of Consumable Item List
	else {} //return 4 of Consumable Item List

	return nullptr;
}

void Monster::Hit(int damage)
{
	if (AvoidRate > GetRandomValue(0, 100)) currentHealth -= damage;
	else currentHealth -= damage * 0.7f;

	if (currentHealth <= 0)
	{
		currentHealth = 0;

		Die();
	}
}

void Monster::Attack()
{
	if (HitRate >= GetRandomValue(0, 100)) APlayer->Hit(damage);
	else APlayer->Hit(damage * 0.5f);
}

void Monster::Die()
{
	for (int i = 0; i < MaxItemCount; i++)
	{
		if (GetRandomValue(MinDropValue, 100) >= 50) APlayer->AddItem(DropItem());
	}

	APlayer->AddGold(500 * Rank);
}

void Monster::TestPrint()
{
	cout << name << " : if Player Level = " << PlayerLevel << ", DungeonLevel = " << DungeonLevel << " : " << name << "Health = " << health << ", " << name << "Damage = " << damage << endl;
}