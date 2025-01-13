#include "Character/Monster/Troll.h"

Troll::Troll(int dLevel) : Monster(dLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	realDamage = damage;
	skill2Counter = 0;
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
	if (skill2Counter > 0)
	{
		skill2Counter--;
		player->Hit(realDamage * 0.3f);
		//cout << name << " �� ���� Damage = " << realDamage * 0.3f << endl;
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

	rank = GetRandomValue(0, dungeonLevel);

	switch (rank)
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

	minDropValue += rank * 10;
	artifactRate += rank * 2;
	maxItemRank += rank * 18;
	hitRate += rank * 5;
	avoidRate += rank * 2;
	maxItemCount += rank / 2;
}

void Troll::NormalAttack() //�Ϲ� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������.
{
	player->Hit(realDamage * 0.8f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.8f << endl;
}

void Troll::FirstSkillAttack() // ��ų 1 �����. ���ݷ��� 130% ��ŭ�� ���ظ� ������.
{
	__super::FirstSkillAttack();

	coolDown1 = 2;
	player->Hit(realDamage * 1.3f);
	//cout << name << " Use Skill 1 Attack. Damage = " << realDamage * 1.3f << endl;
}

void Troll::SecondSkillAttack() // ��ų 2 Ʈ���� ��. 2�� ���� ���ݷ��� 30% ��ŭ�� ���� ���ظ� ������.
{
	__super::SecondSkillAttack();

	coolDown2 = 3;
	skill2Counter = 2;
	//cout << name << " Use Skill 2 Attack" << endl;
}

void Troll::FinalSkillAttack() // ��ų 3 ��� ���� ����. ���ݷ��� 80% ��ŭ�� ���ظ� ������, ��Ʈ���� ��ġ�� 5 ������Ų��.
{
	__super::FinalSkillAttack();

	coolDown3 = 5;
	player->Hit(realDamage * 0.8f);
	//player->stress(5) // TODO : �÷��̾� ��Ʈ���� ��ġ ���� �Ǹ� ���� �ʿ�
	//cout << name << " Use Skill 3 Attack. Damage = " << realDamage * 0.8f << "Add Player Stress 10" << endl;
}
