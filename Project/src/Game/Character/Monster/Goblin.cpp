#include "Character/Monster/Goblin.h"

Goblin::Goblin(int dungeonLevel) : Monster(dungeonLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	RealDamage = damage;
}

Goblin::~Goblin()
{
	
}

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

void Goblin::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	Rank = GetRandomValue(0, DungeonLevel);

	switch (Rank)
	{
	case 0:
		name = "Goblin";
		break;

	case 1:
		name = "Goblin Warrior";
		break;

	case 2:
		name = "Goblin General";
		break;

	case 3:
		name = "Goblin Lord";
		break;
	}

	MinDropValue += Rank * 10;
	ArtifactRate += Rank * 2;
	MaxItemRank += Rank * 18;
	HitRate += Rank * 5;
	AvoidRate += Rank * 2;
	MaxItemCount += Rank / 2;
}

void Goblin::NormalAttack() //일반 공격. 공격력의 70% 만큼의 피해를 입힌다.
{
	//APlayer->Hit(RealDamage * 0.7f);
	cout << name << " Use Normal Attack. Damage = " << RealDamage * 0.7f << endl;
}

void Goblin::FirstSkillAttack()
{
	__super::FirstSkillAttack();
}

void Goblin::SecondSkillAttack()
{
	__super::SecondSkillAttack();
}

void Goblin::FinalSkillAttack()
{
	__super::FinalSkillAttack();
}
