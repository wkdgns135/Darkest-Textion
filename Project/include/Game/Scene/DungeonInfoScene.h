#pragma once
#include "Scene.h"

class DungeonInfoScene : public Scene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};