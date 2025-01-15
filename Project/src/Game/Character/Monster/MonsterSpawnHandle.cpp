#include "Character/Monster/MonsterSpawnHandle.h"
#include <random>

MonsterSpawnHandle::MonsterSpawnHandle()
{

}

MonsterSpawnHandle::~MonsterSpawnHandle()
{

}

Monster* MonsterSpawnHandle::GetSpawnMonsterByDungeonLevel(EDungeon dungeon)
{
	switch (dungeon)
	{
	case Weald: return GetRandomForestMonster();
		break;

	case Cove: return GetRandomSeasideMonster();
		break;

	case DarkestDungeon: return GetRandomDarkestMonster();
		break;
	}

	return nullptr;
}

Monster* MonsterSpawnHandle::GetSpawnBossByDungeonLevel(EDungeon dungeon)
{
	switch (dungeon)
	{
	case Weald: return new BossMonsterHag();
		break;

	case Cove: return new BossMonsterSiren();
		break;

	case DarkestDungeon: return new BossMonsterHeart();
		break;
	}

	return nullptr;
}

int MonsterSpawnHandle::GetRandomValue(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> RandomValue(min, max);

	return RandomValue(gen);
}

Monster* MonsterSpawnHandle::GetRandomForestMonster()
{
	int randValue = GetRandomValue(0, kindOfForestMonster - 1);

	switch (randValue)
	{
	case 0: return new ForestMonsterFungal();
		break;

	case 1: return new ForestMonsterGiant();
		break;

	case 2: return new ForestMonsterCrone();
		break;
	}

	return nullptr;
}

Monster* MonsterSpawnHandle::GetRandomSeasideMonster()
{
	int randValue = GetRandomValue(0, kindOfSeasideMonster - 1);

	switch (randValue)
	{
	case 0: return new SeasideMonsterPelagic();
		break;

	case 1: return new SeasideMonsterStinger();
		break;

	case 2: return new SeasideMonsterThrall();
		break;
	}

	return nullptr;
}

Monster* MonsterSpawnHandle::GetRandomDarkestMonster()
{
	int randValue = GetRandomValue(0, kindOfDarkestMonster - 1);

	switch (randValue)
	{
	case 0: return new DarkestMonsterWitch();
		break;

	case 1: return new DarkestMonsterHound();
		break;

	case 2: return new DarkestMonsterTemplar();
		break;

	case 3: return new DarkestMonsterCyst();
		break;

	case 4: return new DarkestMonsterHorror();
		break;
	}

	return nullptr;
}
