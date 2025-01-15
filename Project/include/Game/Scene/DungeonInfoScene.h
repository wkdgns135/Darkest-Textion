#pragma once
#include "Scene.h"

class DungeonInfoScene : public Scene {
private:
	void InitBackground();
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};