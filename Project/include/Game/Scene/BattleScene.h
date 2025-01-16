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
	Sprite* monsterTurn;

	Sprite* playerAttack;
	Sprite* playerTurn;
	Sprite* playerSkill;

	void ImportMonsterSprite();
	void ImportPlayerSprite();
	void ImportUiSprite();

	void EnableInputEvent();

	void MonsterTurn();
	void PlayerTurn();
	void PlayerAttack(int skillIndex);
	void PlayerAttackFinish(int skillIndex);
	void MonsterAttackFinish();
	void UseInventory();
	void UpdateNumber();
	
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};