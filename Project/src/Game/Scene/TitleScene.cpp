#include "Scene/SceneManager.h"

using namespace std;

void TitleScene::Enter()
{
	cout << "Title Scene enter" << '\n';
	cout << "Press 1: ���� �� ����" << '\n';
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene(EMainScene);});
}

void TitleScene::Update()
{
}

void TitleScene::Exit()
{
	cout << "Title Scene exit" << '\n';
}
