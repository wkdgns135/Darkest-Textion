#include "GameManager.h"
#include "Scene/BattleScene.h"
#include "Character/Monster/MonsterSpawnHandle.h"

void BattleScene::MonsterTurn()
{
	monster->Attack();
	battleState = EMonsterAttack;
}

void BattleScene::PlayerTurn()
{
	InitInputEvent();
	battleState = EStandbyInput;
}

void BattleScene::InitInputEvent()
{
	AddInputEvent(Key_A, [this]() {PlayerAttack(); });
}

void BattleScene::PlayerAttack()
{
	player->SetMonster(monster);
	player->Attack();
	battleState = EPlayerAttack;
}

void BattleScene::Enter()
{
	DungeonScene::Enter();
	GameManager gameManager = GameManager::GetInstance();
	
	player = gameManager.GetPlayer();
	MonsterSpawnHandle monsterSpawner;
	monster = monsterSpawner.GetSpawnMonsterByDungeonLevel(gameManager.GetCurrentDungeon());

	//if (player.GetSpeed() < monster.GetSpeed()) {
	//	battleState = EMonsterAttack;
	//  MonsterTurn()
	//}
	//else {
	//	battleState = EPlayerAttack;
	//  PlayerTurn()
	//}
}

void BattleScene::Update()
{
	DungeonScene::Update();
}

void BattleScene::Exit()
{
	DungeonScene::Exit();
}
