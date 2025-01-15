#pragma once
#include "Global/Global.h"
#include "DesignPattern/Singleton.h"

#include "TitleScene.h"
#include "MainScene.h"
#include "SelectDungeonScene.h"
#include "DungeonInfoScene.h"
#include "NewPlayerScene.h"
#include "DungeonScene.h"
#include "BattleScene.h"
#include "IntroScene.h"
#include "ShopScene.h"

using namespace std;

class SceneManager : public Singleton<SceneManager> {
private:
    unique_ptr<Scene> currentScene;

public:
    template <typename T>
	void ChangeScene() {
		if (currentScene) {
			currentScene->RootExit();
			currentScene->Exit();
		}
		currentScene = move(make_unique<T>());
		if (currentScene) {
			currentScene->RootEnter();
			currentScene->Enter();
		}
		currentScene->RootUpdate();
    }
};