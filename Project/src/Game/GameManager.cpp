#include "GameManager.h"
#include "Global/Global.h"

using namespace std;

void GameManager::StartGame()
{
	SceneManager::GetInstance().ChangeScene(ETitleScene);
}
