#include <iostream>
#include "IO/Renderer.h"
#include "GameManager.h"
#include "Scene/SceneManager.h"
#include "Scene/NewPlayerScene.h"
using namespace std;

void NewPlayerScene::Enter()
{
    system("cls");
    renderer->SetConsoleFontForText();
    cout << "플레이어 이름을 입력하세요: ";
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
