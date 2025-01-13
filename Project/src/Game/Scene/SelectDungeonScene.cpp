#include "IO/OutputManager.h"
#include "Scene/SelectDungeonScene.h"
void SelectDungeonScene::Enter()
{
	OutputManager::GetInstance().PrintAsciiArt(SelectDungeonAsciiArt);
}

void SelectDungeonScene::Update()
{

}

void SelectDungeonScene::Exit()
{

}
