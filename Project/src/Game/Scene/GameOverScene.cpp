#include "Scene/GameOverScene.h"
#include "Scene/SceneManager.h"

void GameOverScene::Enter()
{
	renderer->AddBackground("drawable/GameOver.bmp");
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_3, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_Q, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_W, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_E, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_R, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
}

void GameOverScene::Update()
{
}

void GameOverScene::Exit()
{
}
