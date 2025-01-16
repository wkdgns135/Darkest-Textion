#pragma once
#include "Scene.h"

class GameOverScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};