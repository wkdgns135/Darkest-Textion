#pragma once
#include <cwchar>
#include <windows.h>
#include "Scene/SceneManager.h"

using namespace std;

void TitleScene::Enter()
{
	renderer->AddBackground("drawable/Title.bmp");

	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<NewPlayerScene>(); });

	AddInputEvent(Key_ESC, []() {exit(0); });
	AddInputEvent(Key_3, []() {exit(0); });
}

void TitleScene::Update()
{

}

void TitleScene::Exit()
{
	
}
