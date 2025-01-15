#include "GameManager.h"
#include "Scene/BattleScene.h"

void BattleScene::Enter()
{
	DungeonScene::Enter();
	
	player = GameManager::GetInstance().GetPlayer();
	monster = 
}

void BattleScene::Update()
{
	DungeonScene::Update();
}

void BattleScene::Exit()
{
	DungeonScene::Exit();
}
