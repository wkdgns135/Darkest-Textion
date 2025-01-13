#include "IO/OutputManager.h"
#include "Scene/SceneManager.h"

void SelectDungeonScene::SelectWeald()
{
	name = "삼림 지대";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectCove()
{
	name = "해안 만";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectDarkestDungeon()
{
	name = "가장 어두운 던전";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::Enter()
{
	OutputManager::GetInstance().PrintAsciiArt(SelectDungeonAsciiArt);
	AddInputEvent(Key_1, [this]() {SelectWeald(); });
	AddInputEvent(Key_2, [this]() {SelectCove(); });
	AddInputEvent(Key_3, [this]() {SelectDarkestDungeon(); });
}

void SelectDungeonScene::Update()
{

}

void SelectDungeonScene::Exit()
{
	OutputManager::GetInstance().SetConsoleFontForText();
	cout << name << "을(를) 선택하셨습니다." << '\n';
}