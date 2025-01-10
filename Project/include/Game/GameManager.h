#pragma once
#include "DesignPattern/Singleton.h"
#include "Character/Player/Player.h"

class GameManager : public Singleton<GameManager> {
private:
	Player* player;

public:
	void StartGame();
	inline Player* GetPlayer() { return player; }
};