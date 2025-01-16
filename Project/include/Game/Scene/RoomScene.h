#pragma once
#include "DungeonScene.h"

enum Encounter{
	EBattle,
};

class RoomScene : public DungeonScene{
private:
	void NextRoom();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};