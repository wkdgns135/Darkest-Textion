#include "Scene/SceneManager.h"

using namespace std;

void CallbackText1() {
	cout << "Callback Test 2" << '\n';
}

void CallbackText2() {
	cout << "Complete Test 2" << '\n';
}


void MainScene::Enter()
{
	cout << "MainSceneEnter" << '\n';
	AddInputEvent(Key_1, [this]() { CallbackTest(); }); // ¸â¹ö ÇÔ¼ö
	AddInputEvent(Key_2, CallbackText1, CallbackText2);
}

void MainScene::Update()
{

}

void MainScene::Exit()
{

}

void MainScene::CallbackTest()
{
	cout << "Callback Test 1" << '\n';
}



