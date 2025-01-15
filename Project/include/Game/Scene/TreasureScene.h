#pragma once
#include "DungeonScene.h"
#include "Character/Player/Player.h"

class TreasureScene : public DungeonScene
{
private:
	Player* player;
	Item* item;
	int num;

	void OpenBox();
	void GetItem(int num);
	void GiveUpItem();
	void SelectItem();
	void InitInputEvent();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};