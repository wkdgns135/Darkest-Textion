#include "Character/Monster/MonsterActionHandle.h"

MonsterActionHandle::MonsterActionHandle(Player* character)
{
	player = character;
	monsterAttack = new MonsterAttack(player);
	monsterHit = new MonsterHit(player);
}

MonsterActionHandle::~MonsterActionHandle()
{
	delete monsterAttack;
	delete monsterHit;
	monsterAttack = nullptr;
	monsterHit = nullptr;
}

void MonsterActionHandle::Attack(int value)
{
	monsterAttack->AttackToPlayer(value);
}

void MonsterActionHandle::Hit(int value, int damage, int randValue)
{
	monsterHit->SetReflectionTrigger(monsterAttack->GetReflectionTrigger());
	monsterHit->HitByPlayer(value, damage, randValue);
}