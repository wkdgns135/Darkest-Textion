#include "Character/Monster/MonsterSpawnHandle.h"

int main()
{
	MonsterSpawnHandle spawner;

	Monster* forestMonster = spawner.GetSpawnMonsterByDungeonLevel(0);
	Monster* seasideMonster = spawner.GetSpawnMonsterByDungeonLevel(1);
	Monster* darkestMonster = spawner.GetSpawnMonsterByDungeonLevel(2);
	Monster* easyLevelBoss = spawner.GetSpawnBossByDungeonLevel(0);
	Monster* normalLevelBoss = spawner.GetSpawnBossByDungeonLevel(1);
	Monster* hardLevelBoss = spawner.GetSpawnBossByDungeonLevel(2);

	forestMonster->TestPrint();
	seasideMonster->TestPrint();
	darkestMonster->TestPrint();
	easyLevelBoss->TestPrint();
	normalLevelBoss->TestPrint();
	hardLevelBoss->TestPrint();

	for (int i = 0; i < 10; i++)
	{
		if (forestMonster != nullptr) forestMonster->Attack();
		cout << "\n";
		if (seasideMonster != nullptr)seasideMonster->Attack();
		cout << "\n";
		if (darkestMonster != nullptr)darkestMonster->Attack();
		cout << "\n";
		if (easyLevelBoss != nullptr)easyLevelBoss->Attack();
		cout << "\n";
		if (normalLevelBoss != nullptr)normalLevelBoss->Attack();
		cout << "\n";
		if (hardLevelBoss != nullptr)hardLevelBoss->Attack();
		cout << "\n";
		cout << "\n";

		if (forestMonster != nullptr)forestMonster->Hit(100);
		cout << "\n";
		if (seasideMonster != nullptr)seasideMonster->Hit(100);
		cout << "\n";
		if (darkestMonster != nullptr)darkestMonster->Hit(100);
		cout << "\n";
		if (easyLevelBoss != nullptr)easyLevelBoss->Hit(100);
		cout << "\n";
		if (normalLevelBoss != nullptr)normalLevelBoss->Hit(100);
		cout << "\n";
		if (hardLevelBoss != nullptr)hardLevelBoss->Hit(100);
		cout << "\n";
		cout << "\n";
	}
}