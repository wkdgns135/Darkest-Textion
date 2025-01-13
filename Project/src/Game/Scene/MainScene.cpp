#include "Scene/SceneManager.h"

using namespace std;

void MainScene::Enter()
{
	OutputManager::GetInstance().PrintAsciiArt(MainAsciiArt);
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene(ESelectDungeonScene); });


}

void MainScene::Update()
{

}

void MainScene::Exit()
{
	
}

