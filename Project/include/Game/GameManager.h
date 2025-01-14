#pragma once
#include "DesignPattern/Singleton.h"
#include "Global/ProjectEnum.h"

class Player;
class GameManager : public Singleton<GameManager> {
private:
	Player* player;
	EDungeon currentDungeon;

public:
	inline Player* GetPlayer() { return player; }
	inline void SetPlayer(Player* player) { this->player = player; }
	inline EDungeon GetCurrentDungeon() { return currentDungeon; }
	inline void SetCurrentDungeon(EDungeon dungeon) { currentDungeon = dungeon; }
};