#pragma once
#include "Scene.h"

class TitleScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};