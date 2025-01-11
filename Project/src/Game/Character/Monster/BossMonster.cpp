#include "Character/Monster/BossMonster.h"

#include "Character/Monster/Troll.h"
#include "Character/Monster/Orc.h"
#include "Character/Monster/Goblin.h"

BossMonster::BossMonster(int dungeonLevel) : Monster(dungeonLevel)
{
	switch (DungeonLevel)
	{
	case 0:
		name = "EasyBoss";
		break;

	case 1:
		name = "NormalBoss";
		break;

	case 2:
		name = "HardBoss";
		break;

	case 3:
		name = "Darkest";
		break;
	}

	Rank = 2;
	InitializeByDungeonLevel();
	Magnification();
	currentHealth = health;
}

BossMonster::~BossMonster()
{
	__super::~Monster();
}

Item* BossMonster::DropItem()
{
	return nullptr;
}

void BossMonster::Hit(int damage)
{
	__super::Hit(damage);
}

void BossMonster::Attack()
{
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

int main()
{
	Monster* Boss = new BossMonster(1);
	Monster* troll = new Troll(1);
	Monster* orc = new Orc(1);
	Monster* goblin = new Goblin(1);

	Boss->TestPrint();
	troll->TestPrint();
	orc->TestPrint();
	goblin->TestPrint();
}