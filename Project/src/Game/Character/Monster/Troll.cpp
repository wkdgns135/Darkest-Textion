#include "Character/Monster/Troll.h"

Troll::Troll(int dungeonLevel) : Monster(dungeonLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	RealDamage = damage;
	Skill2Counter = 0;
}

Troll::~Troll()
{
	
}

Item* Troll::DropItem()
{
	return nullptr;
}

void Troll::Hit(int damage)
{
	__super::Hit(damage);
}

void Troll::Attack()
{
	if (Skill2Counter > 0)
	{
		Skill2Counter--;
		//APlayer->Hit(RealDamage * 0.3f);
		cout << name << " 독 지속 Damage = " << RealDamage * 0.3f << endl;
	}
	__super::Attack();
}

void Troll::Die()
{
	__super::Die();
}

void Troll::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	Rank = GetRandomValue(0, DungeonLevel);

	switch (Rank)
	{
	case 0:
		name = "Troll";
		break;

	case 1:
		name = "Troll Warrior";
		break;

	case 2:
		name = "Troll General";
		break;

	case 3:
		name = "Troll Lord";
		break;
	}

	MinDropValue += Rank * 10;
	ArtifactRate += Rank * 2;
	MaxItemRank += Rank * 18;
	HitRate += Rank * 5;
	AvoidRate += Rank * 2;
	MaxItemCount += Rank / 2;
}

void Troll::NormalAttack() //일반 공격. 공격력의 80% 만큼의 피해를 입힌다.
{
	//APlayer->Hit(RealDamage * 0.8f);
	cout << name << " Use Normal Attack. Damage = " << RealDamage * 0.8f << endl;
}

void Troll::FirstSkillAttack() // 스킬 1 짓밟기. 공격력의 130% 만큼의 피해를 입힌다.
{
	__super::FirstSkillAttack();

	CoolDown1 = 2;
	//APlayer->Hit(RealDamage * 1.3f);
	cout << name << " Use Skill 1 Attack. Damage = " << RealDamage * 1.3f << endl;
}

void Troll::SecondSkillAttack() // 스킬 2 트롤의 독. 2턴 동안 공격력의 30% 만큼의 지속 피해를 입힌다.
{
	__super::SecondSkillAttack();

	CoolDown2 = 3;
	Skill2Counter = 2;
	cout << name << " Use Skill 2 Attack" << endl;
}

void Troll::FinalSkillAttack() // 스킬 3 기분 나쁜 감촉. 공격력의 80% 만큼의 피해를 입히고, 스트레스 수치를 10 증가시킨다.
{
	__super::FinalSkillAttack();

	CoolDown3 = 5;
	//APlayer->Hit(RealDamage * 0.8f);
	//APlayer->stress(10)
	cout << name << " Use Skill 3 Attack. Damage = " << RealDamage * 0.8f << "Add Player Stress 10" << endl;
}
