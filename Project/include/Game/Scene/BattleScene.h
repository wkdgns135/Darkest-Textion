#pragma once
#include "DungeonScene.h"

class BattleScene : public DungeonScene {
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};