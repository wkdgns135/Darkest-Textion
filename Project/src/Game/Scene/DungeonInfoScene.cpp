#include <iostream>
#include "IO/OutputManager.h"
#include "Scene/SceneManager.h"

using namespace std;

void DungeonInfoScene::Enter()
{
	cout << "정말로 진입하시겠습니까?\n1: 진입한다\n2: 돌아간다" << '\n';
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
}

void DungeonInfoScene::Update()
{
}

void DungeonInfoScene::Exit()
{
}
