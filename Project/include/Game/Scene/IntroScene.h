#pragma once
#include "Scene.h"

class IntroScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};