#include "Scene/SceneManager.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Artifact/ExpStone.h"
using namespace std;

void MainScene::Enter()
{
	renderer->AddBackground("drawable/Main.bmp");
	Player* player = GameManager::GetInstance().GetPlayer();
	Item* health = new HealthStone();
	Item* snake = new SnakeOil();
	Item* exp = new ExpStone();
	player->AddItem(health, 2);
	player->AddItem(snake, 2);
	player->AddItem(exp,2);


	SetCustomMode();
}

void MainScene::Update()
{

}

void MainScene::Exit()
{
	
}

void MainScene::SetCustomMode()
{
	Scene::SetCustomMode();
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<ShopScene>(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	AddInputEvent(Key_I, [this]() {this->SetInventoryMode(); });
}

