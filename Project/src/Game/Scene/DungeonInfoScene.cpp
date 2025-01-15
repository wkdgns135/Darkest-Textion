#include <iostream>
#include "IO/Renderer.h"
#include "Scene/SceneManager.h"

using namespace std;

void DungeonInfoScene::InitBackground()
{
	switch (GameManager::GetInstance().GetCurrentDungeon())
	{
	case Weald:
		renderer->AddBackground("drawable/WealdInfo.bmp");
		break;
	case Cove:
		renderer->AddBackground("drawable/CoveInfo.bmp");
		break;
	case DarkestDungeon:
		renderer->AddBackground("drawable/DarkestDungeonInfo.bmp");
		break;
	default:
		renderer->AddBackground("drawable/WealdInfo.bmp");
		break;
	}
}


void DungeonInfoScene::Enter()
{
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<DungeonScene>(); });
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<BattleScene>(); });
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<TrapScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });

	InitBackground();
}

void DungeonInfoScene::Update()
{

}

void DungeonInfoScene::Exit()
{

}
