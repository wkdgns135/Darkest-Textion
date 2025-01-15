#pragma once

#include "Character/Monster/ForestMonsters.h"
#include "Character/Monster/SeasideMonsters.h"
#include "Character/Monster/DarkestMonsters.h"
#include "Character//Monster/BossMonster.h"
#include "Global/ProjectEnum.h"

class MonsterSpawnHandle
{
public:
	MonsterSpawnHandle();
	~MonsterSpawnHandle();

	Monster* GetSpawnMonsterByDungeonLevel(EDungeon dungeon);
	Monster* GetSpawnBossByDungeonLevel(EDungeon dungeon);

private:
	const int kindOfForestMonster = 3;
	const int kindOfSeasideMonster = 3;
	const int kindOfDarkestMonster = 5;

	int GetRandomValue(int min, int max);
	
	Monster* GetRandomForestMonster();
	Monster* GetRandomSeasideMonster();
	Monster* GetRandomDarkestMonster();
};
