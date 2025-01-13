#include "Scene/SceneManager.h"

using namespace std;

void MainScene::Enter()
{
	OutputManager::GetInstance().PrintAsciiArt(MainAsciiArt);
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
}

void MainScene::Update()
{

}

void MainScene::Exit()
{
	
}

