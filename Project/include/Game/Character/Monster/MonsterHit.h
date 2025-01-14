#pragma once

#include "Character/Monster/Monster.h"
#include "GameManager.h"

class MonsterHit
{
public :
	MonsterHit(Player* value);
	~MonsterHit();
	
	void SetMonster(Monster* value) { monster = value; }
	void HitByPlayer(int value, int damage, int randValue);
	void SetReflectionTrigger(bool value) { isReflection = value; }

private:
	Monster* monster;
	Player* player;
	bool isReflection;
};