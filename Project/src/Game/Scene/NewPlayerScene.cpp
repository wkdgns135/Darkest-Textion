#include <iostream>
#include "GameManager.h"
#include "Scene/SceneManager.h"
#include "Scene/NewPlayerScene.h"
#include "Scene/IntroScene.h"
using namespace std;

void NewPlayerScene::Enter()
{
    system("cls");
    renderer->SetConsoleFontForText();
    cout << "�÷��̾� �̸��� �Է��ϼ���: ";
    string name;
    cin >> name;
    GameManager::GetInstance().SetPlayer(new Player(name));
    SceneManager::GetInstance().ChangeScene<IntroScene>();
}

void NewPlayerScene::Update()
{
}

void NewPlayerScene::Exit()
{
}
