#pragma once
#include "Scene.h"

class SelectDungeonScene : public Scene{
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};