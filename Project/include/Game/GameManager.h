#pragma once
#include "DesignPattern/Singleton.h"
#include "Global/ProjectEnum.h"

class Player;
class GameManager : public Singleton<GameManager> {
private:
	Player* player;
	EDungeon currentDungeon;
	int currentFloor;

public:
	inline Player* GetPlayer() { return player; }
	inline void SetPlayer(Player* player) { this->player = player; }
	inline EDungeon GetCurrentDungeon() { return currentDungeon; }
	inline void SetCurrentDungeon(EDungeon dungeon) { currentDungeon = dungeon; }
	inline void IncreaseFloor() { currentFloor++; };
	inline int GetFloor() { return currentFloor; };
	inline void SetFloor(int floor) { currentFloor = floor; };
	inline bool IsBossStage() {
		return (currentFloor == 10 && currentDungeon == Weald) ||
			(currentFloor == 20 && currentDungeon == Cove) ||
			(currentFloor == 30 && currentDungeon == DarkestDungeon);
	}
};