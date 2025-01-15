#include "GameManager.h"
#include "Scene/DungeonScene.h"
#include "Scene/SceneManager.h"

void DungeonScene::InitBackground()
{
	switch (GameManager::GetInstance().GetCurrentDungeon())
	{
	case Weald:
		renderer->AddBackground("drawable/Weald.bmp");
		break;
	case Cove:
		renderer->AddBackground("drawable/Cove.bmp");
		break;
	case DarkestDungeon:
		renderer->AddBackground("drawable/DarkestDungeon.bmp");
		break;
	default:
		renderer->AddBackground("drawable/Weald.bmp");
		break;
	}
}

void DungeonScene::Enter()
{
	InitBackground();
}

void DungeonScene::Update()
{

}

void DungeonScene::Exit()
{

}
