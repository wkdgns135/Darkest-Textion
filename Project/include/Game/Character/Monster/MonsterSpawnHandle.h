#pragma once

#include "Character/Monster/ForestMonsters.h"
#include "Character/Monster/SeasideMonsters.h"
#include "Character/Monster/DarkestMonsters.h"
#include "Character//Monster/BossMonster.h"

class MonsterSpawnHandle
{
public:
	MonsterSpawnHandle();
	~MonsterSpawnHandle();

	Monster* GetSpawnMonsterByDungeonLevel(int dungeonLevel);
	Monster* GetSpawnBossByDungeonLevel(int dungeonLevel);

private:
	const int kindOfForestMonster = 3;
	const int kindOfSeasideMonster = 3;
	const int kindOfDarkestMonster = 5;

	int GetRandomValue(int min, int max);
	
	Monster* GetRandomForestMonster();
	Monster* GetRandomSeasideMonster();
	Monster* GetRandomDarkestMonster();
};
