#include "Character/Monster/Goblin.h"

Goblin::Goblin(int dLevel) : Monster(dLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	realDamage = damage;
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

	rank = GetRandomValue(0, dungeonLevel);

	switch (rank)
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

	minDropValue += rank * 10;
	artifactRate += rank * 2;
	maxItemRank += rank * 18;
	hitRate += rank * 5;
	avoidRate += rank * 2;
	maxItemCount += rank / 2;
}

void Goblin::NormalAttack() //일반 공격. 공격력의 70% 만큼의 피해를 입힌다.
{
	player->Hit(realDamage * 0.7f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.7f << endl;
}

void Goblin::FirstSkillAttack() // 스킬 1 불쾌한 울음 소리. 플레이어의 스트레스를 1 증가 시킨다.
{
	__super::FirstSkillAttack();
	
	coolDown1 = 3;
	//player->stress(5) // TODO : 플레이어 스트레스 수치 구현 되면 수정 필요
}

void Goblin::SecondSkillAttack() // 스킬 2 투척. 공격력의 100% 만큼의 피해를 입힌다.
{
	__super::SecondSkillAttack();

	coolDown2 = 2;
	player->Hit(realDamage);
}

void Goblin::FinalSkillAttack() // 스킬 3 집요한 공격. 공격력의 200% 만큼의 피해를 입힌다.
{
	__super::FinalSkillAttack();

	coolDown3 = 4;
	player->Hit(realDamage * 2);
}
