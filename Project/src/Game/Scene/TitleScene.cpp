#include "Scene/SceneManager.h"

using namespace std;

void TitleScene::Enter()
{
	cout << "TitleSceneEnter" << '\n';
	SceneManager::GetInstance().ChangeScene(EMainScene);
}

void TitleScene::Update()
{
}

void TitleScene::Exit()
{
	cout << "TitleSceneExit" << '\n';
}
