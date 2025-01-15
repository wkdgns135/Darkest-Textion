#pragma once

#include "Scene/DungeonScene.h"
#include "Character/Player/Player.h"
#include "GameManager.h"

enum ETrap
{
	Stress = 0,
	Hit
};

class TrapScene : public DungeonScene
{
public:
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

private:
	const int kindOfTrap = 2;

	GameManager gameManager;
	Player* player;

	void SelectSearchOrMove();
	bool IsActiveTrap(EDungeon dungeonRank);
	void RandomTrapEncounter();
	void PrintOnTrap(ETrap trap, int trapValue);
	void PrintAvoidTrap();
};