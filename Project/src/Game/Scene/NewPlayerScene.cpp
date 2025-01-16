#include "Scene/SceneManager.h"
#include "Scene/NewPlayerScene.h"
#include "Scene/IntroScene.h"

void NewPlayerScene::Enter()
{
    GameManager::GetInstance().SetPlayer(new Player("Player"));
    SceneManager::GetInstance().ChangeScene<IntroScene>();
}

void NewPlayerScene::Update()
{
}

void NewPlayerScene::Exit()
{

}
