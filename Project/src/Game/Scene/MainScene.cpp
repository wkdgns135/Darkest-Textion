#include "Scene/SceneManager.h"

using namespace std;

void StaticCallbackTest() {
	cout << "Static function callback" << '\n';
}

void StaticCompleteTest() {
	cout << "Static function complete" << '\n';
}


void MainScene::Enter()
{
	cout << "MainSceneEnter" << '\n';
	AddInputEvent(Key_1, [this]() { MemberCallbackTest(); }, [this]() { MemberCompleteTest(); }); // ¸â¹ö ÇÔ¼ö
	AddInputEvent(Key_2, StaticCallbackTest, StaticCompleteTest);
}

void MainScene::Update()
{

}

void MainScene::Exit()
{

}

void MainScene::MemberCallbackTest()
{
	cout << "Memeber function Callback" << '\n';
}

void MainScene::MemberCompleteTest()
{
	cout << "Memeber function Complete" << '\n';
}



