#pragma once
#include "Global/Global.h"

class Game {
private:
	unique_ptr<GameManager> gameManager;
	unique_ptr<SceneManager> sceneManager;
	unique_ptr<OutputManager> outputManager;
	
public:
	Game();
	void Start();
};