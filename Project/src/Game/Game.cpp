#include "Game.h"

Game::Game()
{
	sceneManager = make_unique<SceneManager>();
	gameManager = make_unique<GameManager>();
	outputManager = make_unique<OutputManager>();
}

void Game::Start()
{
	sceneManager->ChangeScene<TitleScene>();
}