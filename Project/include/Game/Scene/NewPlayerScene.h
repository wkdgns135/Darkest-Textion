#pragma once
#include "Scene.h"

class NewPlayerScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};