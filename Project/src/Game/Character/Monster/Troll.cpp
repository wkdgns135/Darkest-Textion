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
		cout << name << " �� ���� Damage = " << RealDamage * 0.3f << endl;
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

void Troll::NormalAttack() //�Ϲ� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������.
{
	//APlayer->Hit(RealDamage * 0.8f);
	cout << name << " Use Normal Attack. Damage = " << RealDamage * 0.8f << endl;
}

void Troll::FirstSkillAttack() // ��ų 1 �����. ���ݷ��� 130% ��ŭ�� ���ظ� ������.
{
	__super::FirstSkillAttack();

	CoolDown1 = 2;
	//APlayer->Hit(RealDamage * 1.3f);
	cout << name << " Use Skill 1 Attack. Damage = " << RealDamage * 1.3f << endl;
}

void Troll::SecondSkillAttack() // ��ų 2 Ʈ���� ��. 2�� ���� ���ݷ��� 30% ��ŭ�� ���� ���ظ� ������.
{
	__super::SecondSkillAttack();

	CoolDown2 = 3;
	Skill2Counter = 2;
	cout << name << " Use Skill 2 Attack" << endl;
}

void Troll::FinalSkillAttack() // ��ų 3 ��� ���� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������, ��Ʈ���� ��ġ�� 10 ������Ų��.
{
	__super::FinalSkillAttack();

	CoolDown3 = 5;
	//APlayer->Hit(RealDamage * 0.8f);
	//APlayer->stress(10)
	cout << name << " Use Skill 3 Attack. Damage = " << RealDamage * 0.8f << "Add Player Stress 10" << endl;
}
