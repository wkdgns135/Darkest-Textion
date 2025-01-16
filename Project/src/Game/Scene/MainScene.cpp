#include "Scene/SceneManager.h"

using namespace std;

void MainScene::Enter()
{
	renderer->AddBackground("drawable/Main.bmp");
	SetCustomMode();
}

void MainScene::Update()
{

}

void MainScene::Exit()
{
	
}

void MainScene::SetCustomMode()
{
	Scene::SetCustomMode();
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<ShopScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_I, [this]() {this->SetInventoryMode(); });
}

