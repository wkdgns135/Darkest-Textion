#include "GameManager.h"
#include "Global.h"

using namespace std;

void GameManager::StartGame()
{
	SceneManager::GetInstance().ChangeScene(ETitleScene);
}
