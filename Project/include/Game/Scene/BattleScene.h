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

	Sprite* monsterAttackSprite;
	Sprite* monsterTurnSprite;

	Sprite* playerAttackSprite;
	Sprite* playerTurnSprite;
	Sprite* playerSkillSprite;

	void ImportMonsterSprite();
	void ImportPlayerSprite();
	void ImportUiSprite();

	void MonsterTurnMode();
	void PlayerTurnMode();
	void RewardMode(pair<Item*, int> reward);
	void PlayerAttack(int skillIndex);
	void PlayerAttackFinish(int skillIndex);
	void MonsterAttackFinish();
	void UpdateNumber();
	
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};