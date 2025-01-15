#pragma once
#include "DungeonScene.h"
#include "Character/Player/Player.h"

class BattleScene : public DungeonScene {
private :
	Player* player;
	Monster* monster;

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};