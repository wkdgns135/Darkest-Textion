#pragma once
#include "DungeonScene.h"
#include "Character/Player/Player.h"

class TreasureScene : public DungeonScene
{
private:
	GameManager gameManager;
	Player* player;
	Item* item;
	int num;

	void OpenBox();
	void SelectItem();
	void InitInputEvent();
	void SelectGetOrGiveUp();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};