#include "Scene/EndingScene.h"
#include "Scene/SceneManager.h"

void EndingScene::Enter()
{
	renderer->AddBackground("drawable/Ending.bmp");
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_3, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_Q, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_W, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_E, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_R, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
}

void EndingScene::Update()
{

}

void EndingScene::Exit()
{

}
