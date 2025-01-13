#include "Character/Monster/BossMonster.h"

#include "Character/Monster/Troll.h"
#include "Character/Monster/Orc.h"
#include "Character/Monster/Goblin.h"

BossMonster::BossMonster(int dLevel) : Monster(dLevel)
{
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
	skill3Counter = skill2Counter = skill1Counter = 0;
	currentAvoidRate = avoidRate;
	getDamageRate = 0.7f;
	realDamage = damage;
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
	if (skill3Counter > 0)
	{
		if (GetRandomValue(0, 100) < 50)
		{
			player->Hit(damage);
			return;
		}
	}

	if (currentAvoidRate < GetRandomValue(0, 100)) currentHealth -= damage;
	else currentHealth -= damage * getDamageRate;

	if (currentHealth <= 0)
	{
		currentHealth = 0;

		Die();
	}
}

void BossMonster::Attack()
{
	if (skill1Counter > 0)
	{
		--skill1Counter;
		player->Hit(realDamage * 0.8f);
		cout << name << " Skill1 지속 데미지 = " << realDamage * 0.8f << endl;
	}

	if (skill2Counter == 0)
	{
		currentAvoidRate = avoidRate;
		getDamageRate = 0.7f;
	}
	else --skill2Counter;

	if (skill3Counter > 0) --skill3Counter;
	else realDamage = damage;

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

	rank = GetRandomValue(4, 4 + dungeonLevel);

	switch (rank)
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

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 4;
	avoidRate += rank * 3;
	maxItemCount += rank / 2;
}

void BossMonster::NormalAttack() // 일반 공격. 공격력의 90% 만큼의 피해를 입힌다.
{
	//cout << name << " Use Normal Attack Damage = " << realDamage * 0.9f << endl;
	player->Hit(realDamage * 0.9f);
}

void BossMonster::FirstSkillAttack() //스킬 1 빛을 먹는 불꽃. 사용 시 공격력의 150% 만큼의 피해를 입힌 후, 3턴 동안 공격력의 80% 만큼 지속 피해를 입힌다.
{
	__super::FirstSkillAttack();

	coolDown1 = 4;
	skill1Counter = 3;

	//cout << name << " Use Skill 3 Attack Damage = " << realDamage * 1.5f << endl;
	player->Hit(realDamage * 1.5f);
}

void BossMonster::SecondSkillAttack() // 스킬 2 짙어지는 어둠. 5턴 동안 명중률을 50 퍼센트 떨어뜨린다. (회피율 50 상승) 회피시 받는 데미지가 50%로 감소
{
	__super::SecondSkillAttack();

	coolDown2 = 7;
	skill2Counter = 5;

	currentAvoidRate = avoidRate * 1.5f;
	getDamageRate = 0.5f;

	//cout << name << " Use Skill 2. CurrentAvoidRate = " << currentAvoidRate << ", DamageRate = " << getDamageRate << endl;
}

void BossMonster::FinalSkillAttack() // 스킬 3 Darkest. 5턴 동안 플레이어가 공격 시 50% 확률로 플레이어 자신을 공격하게 만들고, 공격력을 50% 상승시킨다.
{
	__super::FinalSkillAttack();

	coolDown3 = 7;
	skill3Counter = 5;
	realDamage *= 1.5f;

	//cout << name << " Use Skill 3. RealDamage = " << realDamage  << endl;
}
/*
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

	//Boss->Attack();
	//troll->Attack();
	//orc->Attack();
	//goblin->Attack();
}
*/