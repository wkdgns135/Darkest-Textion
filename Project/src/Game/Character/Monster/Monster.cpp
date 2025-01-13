#include "Character/Monster/Monster.h"

Monster::Monster(int dLevel)
{
	dungeonLevel = dLevel; 
	//APlayer = GameManager::GetInstance().GetPlayer();
	//PlayerLevel = APlayer->GetLevel();
	playerLevel = 20; //Test

	if (dungeonLevel >= 4) dungeonLevel %= 4;

	coolDown1 = coolDown2 = coolDown3 = 0;
}

Monster::~Monster()
{
	player == nullptr;
}

void Monster::Magnification()
{
	health = GetRandomValue(20, 30) * playerLevel * (rank + 1);
	damage = GetRandomValue(5, 10) * playerLevel * (rank + 1);
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
	minDropValue = 0;
	artifactRate = 0;
	maxItemRank = 40;
	maxItemCount = 1;
	hitRate = 70;
	avoidRate = 0;
}

Item* Monster::DropItem()
{
	if (artifactRate >= GetRandomValue(0, 100))
	{
		int ItemRankValue = GetRandomValue(0, maxItemRank);

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
	if (avoidRate < GetRandomValue(0, 100)) currentHealth -= damage;
	else currentHealth -= damage * 0.7f;

	cout << name << " Get Hit, current Hp is " << currentHealth << endl;

	if (currentHealth <= 0)
	{
		currentHealth = 0;

		Die();
	}
}

void Monster::Attack()
{
	if (coolDown1 > 0) --coolDown1;
	if (coolDown2 > 0) --coolDown2;
	if (coolDown3 > 0) --coolDown3;

	int Skill = GetRandomValue(0, rank % 4);

	switch (Skill)
	{
	case 0:
		NormalAttack();
		break;

	case 1:
		FirstSkillAttack();
		break;

	case 2:
		SecondSkillAttack();
		break;

	case 3:
		FinalSkillAttack();
		break;
	}
}

void Monster::Die()
{
	for (int i = 0; i < maxItemCount; i++)
	{
		if (GetRandomValue(minDropValue, 100) >= 50) player->AddItem(DropItem());
	}

	player->AddGold(500 * rank);
}

void Monster::FirstSkillAttack()
{
	if (coolDown1 > 0)
	{
		NormalAttack();
		return;
	}
}

void Monster::SecondSkillAttack()
{
	if (coolDown2 > 0)
	{
		FirstSkillAttack();
		return;
	}
}

void Monster::FinalSkillAttack()
{
	if (coolDown3 > 0)
	{
		SecondSkillAttack();
		return;
	}
}

void Monster::TestPrint()
{
	cout << name << " : if Player Level = " << playerLevel << ", DungeonLevel = " << dungeonLevel << " : \n"
		<< "Rank = " << rank << ", Health = " << health << ", Damage = " << damage << "\n"
		<< "Min Drop Value = " << minDropValue << ", MaxItemRank = " << maxItemRank << ", MaxItemCount = " << maxItemCount << "\n"
		<< "AtrtifactRate = " << artifactRate << ", HitRate = " << hitRate << ", AvoidRate = " << avoidRate << "\n" << endl;
}