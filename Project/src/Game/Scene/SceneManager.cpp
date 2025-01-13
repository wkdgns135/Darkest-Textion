#include "Scene/SceneManager.h"

unique_ptr<Scene> SceneManager::ChangeEScene(EScene target)
{
	switch (target)
	{
	case ETitleScene:
		return make_unique<TitleScene>();
	case EMainScene:
		return make_unique<MainScene>();
	case ESelectDungeonScene:
		return make_unique<SelectDungeonScene>();
	default:
		break;
	}
	return nullptr;
}

void SceneManager::ChangeScene(EScene newScene)
{
	if (currentScene) {
		currentScene->Exit();
		currentScene->RootExit();
	}
	currentScene = move(ChangeEScene(newScene));
	if (currentScene) {
		currentScene->Enter();
		currentScene->RootEnter();
	}
	currentScene->RootUpdate();
}
