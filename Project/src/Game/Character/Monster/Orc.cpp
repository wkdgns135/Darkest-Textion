#include "Character/Monster/Orc.h"

Orc::Orc(int dLevel) : Monster(dLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	realDamage = damage;
}

Orc::~Orc()
{
	
}

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

void Orc::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, dungeonLevel);

	switch (rank)
	{
	case 0:
		name = "Orc";
		break;

	case 1:
		name = "Orc Warrior";
		break;

	case 2:
		name = "Orc General";
		break;

	case 3:
		name = "Orc Lord";
		break;
	}

	minDropValue += rank * 10;
	artifactRate += rank * 2;
	maxItemRank += rank * 18;
	hitRate += rank * 5;
	avoidRate += rank * 2;
	maxItemCount += rank / 2;
}

void Orc::NormalAttack() // 일반 공격. 공격력의 80% 만큼의 피해를 입힌다.
{
	player->Hit(realDamage * 0.8f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.8f << endl;
}

void Orc::FirstSkillAttack() // 스킬1 강타. 공격력의 120% 만큼의 피해를 입힌다.
{
	__super::FirstSkillAttack();

	coolDown1 = 1;
	
	player->Hit(realDamage * 1.2f);
	//cout << name << " Use First Skill Attack. Damage = " << realDamage * 1.2f << endl;
}

void Orc::SecondSkillAttack() // 스킬 2 강타 2. 공격력의 150% 만큼의 피해를 입힌다.
{
	__super::SecondSkillAttack();

	coolDown2 = 2;
	
	player->Hit(realDamage * 1.5f);
	//cout << name << " Use Second Skill Attack. Damage = " << realDamage * 1.5f << endl;
}

void Orc::FinalSkillAttack() // 스킬 3 광포화. 이번 전투에서 공격력을 10% 만큼 누적 상승시킨다.
{
	__super::FinalSkillAttack();

	coolDown3 = 3;
	realDamage = damage * 1.1f;

	//cout << name << " Use Final Skill. Enhanced Damage = " << damage << endl;
}
