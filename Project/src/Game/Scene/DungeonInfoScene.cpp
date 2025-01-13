#include <iostream>
#include "IO/OutputManager.h"
#include "Scene/SceneManager.h"

using namespace std;

void DungeonInfoScene::Enter()
{
	cout << "������ �����Ͻðڽ��ϱ�?\n1: �����Ѵ�\n2: ���ư���" << '\n';
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
}

void DungeonInfoScene::Update()
{
}

void DungeonInfoScene::Exit()
{
}
