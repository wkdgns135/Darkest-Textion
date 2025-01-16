#pragma once
#include "DungeonScene.h"

enum Encounter{
	EBattle,
};

class RoomScene : public DungeonScene{
private:
	class Player* player;

	void ChooseMode();
	void InventoryMode();
	
	void NextRoom();
	void UseItem();
	void UpdateNumber();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};