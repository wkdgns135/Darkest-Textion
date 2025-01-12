#include "Character/Monster/Orc.h"

Orc::Orc(int dungeonLevel) : Monster(dungeonLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	RealDamage = damage;
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

	Rank = GetRandomValue(0, DungeonLevel);

	switch (Rank)
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

	MinDropValue += Rank * 10;
	ArtifactRate += Rank * 2;
	MaxItemRank += Rank * 18;
	HitRate += Rank * 5;
	AvoidRate += Rank * 2;
	MaxItemCount += Rank / 2;
}

void Orc::NormalAttack() // �Ϲ� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������.
{
	//APlayer->Hit(RealDamage * 0.8f);
	cout << name << " Use Normal Attack. Damage = " << RealDamage * 0.8f << endl;
}

void Orc::FirstSkillAttack() // ��ų1 ��Ÿ. ���ݷ��� 120% ��ŭ�� ���ظ� ������.
{
	__super::FirstSkillAttack();

	CoolDown1 = 1;
	
	//APlayer->Hit(RealDamage * 1.2f);
	cout << name << " Use First Skill Attack. Damage = " << RealDamage * 1.2f << endl;
}

void Orc::SecondSkillAttack() // ��ų 2 ��Ÿ 2. ���ݷ��� 150% ��ŭ�� ���ظ� ������.
{
	__super::SecondSkillAttack();

	CoolDown2 = 2;
	
	//APlayer->Hit(RealDamage * 1.5f);
	cout << name << " Use Second Skill Attack. Damage = " << RealDamage * 1.5f << endl;
}

void Orc::FinalSkillAttack() // ��ų 3 ����ȭ. �̹� �������� ���ݷ��� 10% ��ŭ ���� ��½�Ų��.
{
	__super::FinalSkillAttack();

	CoolDown3 = 3;
	RealDamage = damage * 1.1f;

	cout << name << " Use Final Skill. Enhanced Damage = " << damage << endl;
}
