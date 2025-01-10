#pragma once
#include "Scene.h"

class MainScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};