#pragma once
#include "Scene.h"

class EndingScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};