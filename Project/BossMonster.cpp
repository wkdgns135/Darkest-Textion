#include "BossMonster.h"

#include "Troll.h"
#include "Orc.h"
#include "Goblin.h"

BossMonster::BossMonster(int dungeonLevel, int playerLevel) : Monster(dungeonLevel, playerLevel)
{
	switch (DungeonLevel)
	{
	case 0:
		Name = "EasyBoss";
		break;

	case 1:
		Name = "NormalBoss";
		break;

	case 2:
		Name = "HardBoss";
		break;

	case 3:
		Name = "Darkest";
		break;
	}

	Magnification();
	CurrentHealth = Health;
}

BossMonster::~BossMonster()
{

}

//string BossMonster::GetName() const
//{
//	return Name;
//}

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

	Health *= 1.5f;
	Damage *= 1.5f;
}

int main()
{
	Monster* Boss = new BossMonster(1, 5);
	Monster* troll = new Troll(1, 5);
	Monster* orc = new Orc(1, 5);
	Monster* goblin = new Goblin(1, 5);

	Boss->TestPrint();
	troll->TestPrint();
	orc->TestPrint();
	goblin->TestPrint();
}