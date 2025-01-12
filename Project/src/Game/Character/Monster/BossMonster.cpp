#include "Character/Monster/BossMonster.h"

#include "Character/Monster/Troll.h"
#include "Character/Monster/Orc.h"
#include "Character/Monster/Goblin.h"

BossMonster::BossMonster(int dungeonLevel) : Monster(dungeonLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	Skill3Counter = Skill2Counter = Skill1Counter = 0;
	GetDamageRate = 0.7f;
	RealDamage = damage;
}

BossMonster::~BossMonster()
{
	
}

Item* BossMonster::DropItem()
{
	return nullptr;
}

void BossMonster::Hit(int damage)
{
	if (Skill3Counter > 0)
	{
		if (GetRandomValue(0, 100) < 50)
		{
			//APlayer->Hit(damage);
			return;
		}
	}

	if (CurrentAvoidRate < GetRandomValue(0, 100)) currentHealth -= damage;
	else currentHealth -= damage * GetDamageRate;

	if (currentHealth <= 0)
	{
		currentHealth = 0;

		Die();
	}
}

void BossMonster::Attack()
{
	if (Skill1Counter > 0)
	{
		--Skill1Counter;
		//APlayer->Hit(RealDamage * 0.8f);
		cout << name << " Skill1 ���� ������ = " << RealDamage * 0.8f << endl;
	}

	if (Skill2Counter == 0)
	{
		CurrentAvoidRate = AvoidRate;
		GetDamageRate = 0.7f;
	}
	else --Skill2Counter;

	if (Skill3Counter > 0) --Skill3Counter;
	else RealDamage = damage;

	__super::Attack();
}

void BossMonster::Die()
{
	__super::Die();
}

void BossMonster::Magnification()
{
	__super::Magnification();

	health *= 1.5f;
	damage *= 1.5f;
}

void BossMonster::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	Rank = GetRandomValue(4, 4 + DungeonLevel);

	switch (Rank)
	{
	case 4:
		name = "EasyBoss";
		break;

	case 5:
		name = "NormalBoss";
		break;

	case 6:
		name = "HardBoss";
		break;

	case 7:
		name = "Darkest";
		break;
	}

	MinDropValue += Rank * 10;
	ArtifactRate += Rank * 4;
	MaxItemRank += Rank * 10;
	HitRate += Rank * 4;
	AvoidRate += Rank * 3;
	MaxItemCount += Rank / 2;
}

void BossMonster::NormalAttack() // �Ϲ� ����. ���ݷ��� 90% ��ŭ�� ���ظ� ������.
{
	cout << name << " Use Normal Attack Damage = " << RealDamage * 0.9f << endl;
	//APlayer->Hit(RealDamage * 0.9f);
}

void BossMonster::FirstSkillAttack() //��ų 1 ���� �Դ� �Ҳ�. ��� �� ���ݷ��� 150% ��ŭ�� ���ظ� ���� ��, 3�� ���� ���ݷ��� 80% ��ŭ ���� ���ظ� ������.
{
	__super::FirstSkillAttack();

	CoolDown1 = 4;
	Skill1Counter = 3;

	cout << name << " Use Skill 3 Attack Damage = " << RealDamage * 1.5f << endl;
	//APlayer->Hit(RealDamage * 1.5f);
}

void BossMonster::SecondSkillAttack() // ��ų 2 £������ ���. 5�� ���� ���߷��� 50 �ۼ�Ʈ ����߸���. (ȸ���� 50 ���) ȸ�ǽ� �޴� �������� 50%�� ����
{
	__super::SecondSkillAttack();

	CoolDown2 = 7;
	Skill2Counter = 5;

	CurrentAvoidRate = AvoidRate * 1.5f;
	GetDamageRate = 0.5f;

	cout << name << " Use Skill 2. CurrentAvoidRate = " << CurrentAvoidRate << ", DamageRate = " << GetDamageRate << endl;
}

void BossMonster::FinalSkillAttack() // ��ų 3 Darkest. 5�� ���� �÷��̾ ���� �� 50% Ȯ���� �÷��̾� �ڽ��� �����ϰ� �����, ���ݷ��� 50% ��½�Ų��.
{
	__super::FinalSkillAttack();

	CoolDown3 = 7;
	Skill3Counter = 5;
	RealDamage *= 1.5f;

	cout << name << " Use Skill 3. RealDamage = " << RealDamage  << endl;
}

int main()
{
	Monster* Boss = new BossMonster(3);
	Monster* troll = new Troll(3);
	Monster* orc = new Orc(3);
	Monster* goblin = new Goblin(3);

	Boss->TestPrint();
	troll->TestPrint();
	orc->TestPrint();
	goblin->TestPrint();

	Boss->Attack();
	troll->Attack();
	orc->Attack();
	goblin->Attack();
}