#pragma once
#include "DesignPattern/Singleton.h"
#include "Character/Player/Player.h"

class GameManager : public Singleton<GameManager> {
private:
	Player* player;

public:
	inline Player* GetPlayer() { return player; }
};