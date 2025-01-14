#include "IO/Renderer.h"
#include "Scene/SceneManager.h"

void SelectDungeonScene::SelectWeald()
{
	GameManager::GetInstance().SetCurrentDungeon(Weald);
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectCove()
{
	GameManager::GetInstance().SetCurrentDungeon(Cove);
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectDarkestDungeon()
{
	GameManager::GetInstance().SetCurrentDungeon(DarkestDungeon);
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::Enter()
{
	renderer->AddBackground("drawable/SelectDungeon.bmp");
	AddInputEvent(Key_1, [this]() {SelectWeald(); });
	AddInputEvent(Key_2, [this]() {SelectCove(); });
	AddInputEvent(Key_3, [this]() {SelectDarkestDungeon(); });
	AddInputEvent(Key_ESC, [this]() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
}

void SelectDungeonScene::Update()
{

}

void SelectDungeonScene::Exit()
{
	
}