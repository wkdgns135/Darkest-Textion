#pragma once
#include <cwchar>
#include <windows.h>
#include "Scene/SceneManager.h"

using namespace std;

void TitleScene::Enter()
{
	OutputManager outputManager = OutputManager::GetInstance();
	outputManager.PrintAsciiArt(TitleAsciiArt);

	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene(EMainScene); });
}

void TitleScene::Update()
{
}

void TitleScene::Exit()
{
	
}
