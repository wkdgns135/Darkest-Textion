#pragma once
#include "DungeonScene.h"
#include "Character/Player/Player.h"

enum BattleState {
	EStandbyInput,
	EPlayerAttack,
	EMonsterAttack,
};

class BattleScene : public DungeonScene {
private :
	Player* player;
	Monster* monster;
	BattleState battleState;

	Sprite* monsterAttack;

	void ImportMonsterSprite();
	void ImportPlayerSprite();
	void ImportUiSprite();

	void MonsterTurn();
	void PlayerTurn();
	void InitInputEvent();
	void PlayerAttack();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};