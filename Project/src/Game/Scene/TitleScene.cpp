#include "Scene/SceneManager.h"

using namespace std;

void TitleScene::Enter()
{
	cout << "Press 1: 메인 신 진입" << '\n';
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene(EMainScene);});
}

void TitleScene::Update()
{
}

void TitleScene::Exit()
{
}
