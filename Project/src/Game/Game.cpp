#include "Game.h"

Game::Game()
{
	sceneManager = make_unique<SceneManager>();
	gameManager = make_unique<GameManager>();
}

void Game::Start()
{
	//sceneManager->ChangeScene<TitleScene>();
	sceneManager->ChangeScene<ShopScene>();
}