#include <iostream>
#include <random>
#include <vector>
#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterActionHandle.h"
#include "Character/Player/Player.h"

Monster::Monster()
{
	player = GameManager::GetInstance().GetPlayer();
	dropItemObj = new DropItemObj;
	monsterActionHandle = new MonsterActionHandle(player);

	playerLevel = player->GetLevel();
}

Monster::~Monster()
{
	delete dropItemObj;
	delete monsterActionHandle;
	player = nullptr;
	dropItemObj = nullptr;
	monsterActionHandle = nullptr;
}

void Monster::Magnification()
{
	health = GetRandomValue(20, 30) * (playerLevel + (rank + 1));
	damage = GetRandomValue(5, 10) * (playerLevel + (rank + 1));
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
	skillName = "";
	
	hitRate = 70;
	avoidRate = 0;
	damageRate = 0.7f;
	criticalRate = 0;
	speed = 0;
	
	minDropValue = 0;
	artifactRate = 0;
	maxItemRank = 40;
	maxItemCount = 1;

	isSturn = false;
	turnOfSturn = 0;
}

Item* Monster::DropItem()
{
	if (artifactRate >= GetRandomValue(0, 100))
	{
		int ItemRankValue = GetRandomValue(0, maxItemRank);
		int ItemIndexValue = GetRandomValue(0, 100);

		return (Item*)dropItemObj->GetArtifactItem(ItemRankValue, ItemIndexValue);
	}

	int RandomConsumableValue = GetRandomValue(0, 100);

	return (Item*)dropItemObj->GetConsumableItem(RandomConsumableValue);
}

void Monster::Hit(int damage)
{
	int checkAvoidValue = GetRandomValue(0, 100);
	int reflectionValue = GetRandomValue(0, 100);
	monsterActionHandle->Hit(checkAvoidValue, damage, reflectionValue);
}

void Monster::Attack()
{
	int maxValue = 2;

	if (GetMonsterType() >= 40) maxValue = 3;

	int skill = GetRandomValue(0, maxValue);
	int criticalValue = GetRandomValue(0, 100);
	int hitValue = GetRandomValue(0, 100);

	monsterActionHandle->Attack(skill, criticalValue, hitValue);
}

void Monster::Die()
{
	for (int i = 0; i < maxItemCount; i++) if (GetRandomValue(minDropValue, 100) >= 50) player->AddItem(DropItem(), 1);
	player->AddGold(500 * rank);
}

void Monster::TestPrint()
{
	cout << name << " : if Player Level = " << playerLevel <<  "\n"
		<< "Rank = " << rank << ", Health = " << health << ", Damage = " << damage << "\n"
		<< "Min Drop Value = " << minDropValue << ", MaxItemRank = " << maxItemRank << ", MaxItemCount = " << maxItemCount << "\n"
		<< "AtrtifactRate = " << artifactRate << ", HitRate = " << hitRate << ", AvoidRate = " << avoidRate << "\n" << endl;
}