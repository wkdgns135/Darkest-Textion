#include <iostream>
#include "IO/Renderer.h"
#include "Scene/SceneManager.h"

using namespace std;

void DungeonInfoScene::Enter()
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
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
}

void DungeonInfoScene::Update()
{

}

void DungeonInfoScene::Exit()
{

}
