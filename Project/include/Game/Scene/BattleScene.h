#pragma once
#include "DungeonScene.h"
#include "Character/Player/Player.h"
#include "GameManager.h"

enum BattleState {
	EStandbyInput,
	EPlayerAttack,
	EMonsterAttack,
};

class BattleScene : public DungeonScene {
private :
	GameManager gameManager;
	Player* player;
	Monster* monster;
	EDungeon dungeon;
	BattleState battleState;

	Sprite* monsterAttackSprite;
	Sprite* monsterTurnSprite;

	vector<Sprite*> playerSkill;

	Sprite* playerSkillPanel;
	Sprite* playerTurnSprite;

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