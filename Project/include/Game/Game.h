#pragma once
#include "Global/Global.h"

class Game {
private:
	unique_ptr<GameManager> gameManager;
	unique_ptr<SceneManager> sceneManager;
	
public:
	Game();
	void Start();
};