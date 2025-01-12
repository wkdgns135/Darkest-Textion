#include "Character/Monster/Monster.h"

Monster::Monster(int dungeonLevel)
{
	DungeonLevel = dungeonLevel; 
	//APlayer = GameManager::GetInstance().GetPlayer();
	//PlayerLevel = APlayer->GetLevel();
	PlayerLevel = 20; //Test

	if (DungeonLevel >= 4) DungeonLevel %= 4;

	CoolDown1 = CoolDown2 = CoolDown3 = 0;
}

Monster::~Monster()
{
	APlayer == nullptr;
}

void Monster::Magnification()
{
	health = GetRandomValue(20, 30) * PlayerLevel * (Rank + 1);
	damage = GetRandomValue(5, 10) * PlayerLevel * (Rank + 1);
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
	MinDropValue = 0;
	ArtifactRate = 0;
	MaxItemRank = 40;
	MaxItemCount = 1;
	HitRate = 70;
	AvoidRate = 0;
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
	if (AvoidRate < GetRandomValue(0, 100)) currentHealth -= damage;
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
	if (CoolDown1 > 0) --CoolDown1;
	if (CoolDown2 > 0) --CoolDown2;
	if (CoolDown3 > 0) --CoolDown3;

	int Skill = GetRandomValue(0, Rank % 4);

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
	for (int i = 0; i < MaxItemCount; i++)
	{
		if (GetRandomValue(MinDropValue, 100) >= 50) APlayer->AddItem(DropItem());
	}

	APlayer->AddGold(500 * Rank);
}

void Monster::FirstSkillAttack()
{
	if (CoolDown1 > 0)
	{
		NormalAttack();
		return;
	}
}

void Monster::SecondSkillAttack()
{
	if (CoolDown2 > 0)
	{
		FirstSkillAttack();
		return;
	}
}

void Monster::FinalSkillAttack()
{
	if (CoolDown3 > 0)
	{
		SecondSkillAttack();
		return;
	}
}

void Monster::TestPrint()
{
	cout << name << " : if Player Level = " << PlayerLevel << ", DungeonLevel = " << DungeonLevel << " : \n"
		<< "Rank = " << Rank << ", Health = " << health << ", Damage = " << damage << "\n"
		<< "Min Drop Value = " << MinDropValue << ", MaxItemRank = " << MaxItemRank << ", MaxItemCount = " << MaxItemCount << "\n"
		<< "AtrtifactRate = " << ArtifactRate << ", HitRate = " << HitRate << ", AvoidRate = " << AvoidRate << "\n" << endl;
}