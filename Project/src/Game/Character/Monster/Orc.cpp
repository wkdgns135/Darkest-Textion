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

void Orc::NormalAttack() // �Ϲ� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������.
{
	player->Hit(realDamage * 0.8f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.8f << endl;
}

void Orc::FirstSkillAttack() // ��ų1 ��Ÿ. ���ݷ��� 120% ��ŭ�� ���ظ� ������.
{
	__super::FirstSkillAttack();

	coolDown1 = 1;
	
	player->Hit(realDamage * 1.2f);
	//cout << name << " Use First Skill Attack. Damage = " << realDamage * 1.2f << endl;
}

void Orc::SecondSkillAttack() // ��ų 2 ��Ÿ 2. ���ݷ��� 150% ��ŭ�� ���ظ� ������.
{
	__super::SecondSkillAttack();

	coolDown2 = 2;
	
	player->Hit(realDamage * 1.5f);
	//cout << name << " Use Second Skill Attack. Damage = " << realDamage * 1.5f << endl;
}

void Orc::FinalSkillAttack() // ��ų 3 ����ȭ. �̹� �������� ���ݷ��� 10% ��ŭ ���� ��½�Ų��.
{
	__super::FinalSkillAttack();

	coolDown3 = 3;
	realDamage = damage * 1.1f;

	//cout << name << " Use Final Skill. Enhanced Damage = " << damage << endl;
}
