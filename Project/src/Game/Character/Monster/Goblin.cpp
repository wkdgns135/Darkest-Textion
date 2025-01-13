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

void Goblin::NormalAttack() //�Ϲ� ����. ���ݷ��� 70% ��ŭ�� ���ظ� ������.
{
	player->Hit(realDamage * 0.7f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.7f << endl;
}

void Goblin::FirstSkillAttack() // ��ų 1 ������ ���� �Ҹ�. �÷��̾��� ��Ʈ������ 1 ���� ��Ų��.
{
	__super::FirstSkillAttack();
	
	coolDown1 = 3;
	//player->stress(5) // TODO : �÷��̾� ��Ʈ���� ��ġ ���� �Ǹ� ���� �ʿ�
}

void Goblin::SecondSkillAttack() // ��ų 2 ��ô. ���ݷ��� 100% ��ŭ�� ���ظ� ������.
{
	__super::SecondSkillAttack();

	coolDown2 = 2;
	player->Hit(realDamage);
}

void Goblin::FinalSkillAttack() // ��ų 3 ������ ����. ���ݷ��� 200% ��ŭ�� ���ظ� ������.
{
	__super::FinalSkillAttack();

	coolDown3 = 4;
	player->Hit(realDamage * 2);
}
