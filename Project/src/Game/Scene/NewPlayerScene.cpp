#include <iostream>
#include "IO/OutputManager.h"
#include "GameManager.h"
#include "Scene/SceneManager.h"
#include "Scene/NewPlayerScene.h"
using namespace std;

void NewPlayerScene::Enter()
{
    OutputManager::GetInstance().SetConsoleFontForText();
    cout << "�÷��̾� �̸��� �Է��ϼ���: ";
    string name;
    cin >> name;
    GameManager::GetInstance().SetPlayer(new Player(name));
    SceneManager::GetInstance().ChangeScene<MainScene>();
}

void NewPlayerScene::Update()
{
}

void NewPlayerScene::Exit()
{
}
