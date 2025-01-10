#pragma once
#include "Global.h"
#include "Singleton.h"

#include "TitleScene.h"
#include "MainScene.h"

using namespace std;

class SceneManager : public Singleton<SceneManager> {
private:
    unique_ptr<Scene> currentScene;
    unique_ptr<Scene> ChangeEScene(EScene target);

public:
    void ChangeScene(EScene newScene);
};