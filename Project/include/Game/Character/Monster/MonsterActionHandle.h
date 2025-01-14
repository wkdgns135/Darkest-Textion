#pragma once
#include "Character/Monster/MonsterAttack.h"
#include "Character/Monster/MonsterHit.h"

class MonsterActionHandle
{
public:
	MonsterActionHandle(Player* character);
	~MonsterActionHandle();

	inline MonsterAttack* GetMonsterAttack() { return monsterAttack; }
	inline MonsterHit* GetMonsterHit() { return monsterHit; }

	void Attack(int value);
	void Hit(int value, int damage, int randValue);

private:
	MonsterAttack* monsterAttack;
	MonsterHit* monsterHit;
	Player* player;
};