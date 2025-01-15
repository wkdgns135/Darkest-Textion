#include "Scene/SceneManager.h"
using namespace std;

void MainScene::Enter()
{
	renderer->AddBackground("drawable/Main.bmp");
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<ShopScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
}

void MainScene::Update()
{

}

void MainScene::Exit()
{
	
}

