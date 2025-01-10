#pragma once
#include "Singleton.h"
#include "Player.h"

class GameManager : public Singleton<GameManager> {
private:
	Player* player;

public:
	void StartGame();
};