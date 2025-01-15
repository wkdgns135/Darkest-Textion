#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Scene/IntroScene.h"
#include "Scene/SceneManager.h"

void IntroScene::Enter()
{
	vector<string> path;
    for (int i = 1; i <= 517; i++) {
        ostringstream oss;
        oss << "drawable/Intro/" << setw(4) << setfill('0') << i << ".bmp";
        path.push_back(oss.str());
    }

    Sprite* intro = new Sprite({0,0}, 500, 300);
    renderer->AddSprite(intro);
    intro->AddAnimation(path, 0.15);
    intro->animation->PlayOnce([]() { SceneManager::GetInstance().ChangeScene<MainScene>();});
    AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
}

void IntroScene::Update()
{
}

void IntroScene::Exit()
{
}
