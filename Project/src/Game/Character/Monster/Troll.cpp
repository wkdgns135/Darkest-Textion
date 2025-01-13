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
		//cout << name << " 독 지속 Damage = " << realDamage * 0.3f << endl;
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

void Troll::NormalAttack() //일반 공격. 공격력의 80% 만큼의 피해를 입힌다.
{
	player->Hit(realDamage * 0.8f);
	//cout << name << " Use Normal Attack. Damage = " << realDamage * 0.8f << endl;
}

void Troll::FirstSkillAttack() // 스킬 1 짓밟기. 공격력의 130% 만큼의 피해를 입힌다.
{
	__super::FirstSkillAttack();

	coolDown1 = 2;
	player->Hit(realDamage * 1.3f);
	//cout << name << " Use Skill 1 Attack. Damage = " << realDamage * 1.3f << endl;
}

void Troll::SecondSkillAttack() // 스킬 2 트롤의 독. 2턴 동안 공격력의 30% 만큼의 지속 피해를 입힌다.
{
	__super::SecondSkillAttack();

	coolDown2 = 3;
	skill2Counter = 2;
	//cout << name << " Use Skill 2 Attack" << endl;
}

void Troll::FinalSkillAttack() // 스킬 3 기분 나쁜 감촉. 공격력의 80% 만큼의 피해를 입히고, 스트레스 수치를 5 증가시킨다.
{
	__super::FinalSkillAttack();

	coolDown3 = 5;
	player->Hit(realDamage * 0.8f);
	//player->stress(5) // TODO : 플레이어 스트레스 수치 구현 되면 수정 필요
	//cout << name << " Use Skill 3 Attack. Damage = " << realDamage * 0.8f << "Add Player Stress 10" << endl;
}
