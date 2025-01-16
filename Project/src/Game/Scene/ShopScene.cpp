#include <string>
#include "Scene/SceneManager.h"
#include "Shop/Shop.h"
#include "Global/ProjectEnum.h"
#include "Global/Global.h"
#include "Character/Player/Player.h"
#include "IO/Sprite.h"

//TODO : delete after Test
#include "Item/Consumable/HealthPotion.h"
#include "Item/Consumable/DamageBoost.h"
#include "Item/Consumable/Laudanum.h"
#include "Item/Artifact/RareArtifact.h"
#include <string>
using namespace std;



ShopScene::ShopScene()
{
	cursor = 0;
	//HERE: player Setting for Test
	Player* player = GameManager::GetInstance().GetPlayer();
	player->AddGold(500);
}

void ShopScene::Enter()
{
	shop = make_unique<Shop>();
	shop->InitializeOnlyConsumable();

	//background
	renderer->AddBackground("drawable/background/ShopBackground2.bmp");


	//goldPannel
	ShowGoldPannel();

	SetPurchaseMode();


}

void ShopScene::Update()
{

}

void ShopScene::Exit()
{

}

void ShopScene::SetPurchaseMode() 
{
	ClearEvent();

	renderer->ClearSprite();
	ShowGoldPannel();
	DisplayShopItems();


	cursorLoc = { { 260, 0 }, { 299, 0 }, { 338, 0 } };
	cursor = 0;
	ShowCursor();




	AddInputEvent(EKeyEvent::Key_1, [this]() { MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { MoveCursor(1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { this->Purchase(); });
	AddInputEvent(EKeyEvent::Key_I, [this]() { this->SetSellMode(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
}

void ShopScene::SetSellMode()
{
	ClearEvent();

	renderer->ClearSprite();
	ShowGoldPannel();
	DisplayShopItems();
	ShowInventory();

	cursor = 0;
	ShowCursor();

	AddInputEvent(EKeyEvent::Key_1, [this]() { MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { MoveCursor(1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { this->Sell(); });
	AddInputEvent(EKeyEvent::Key_I, [this]() { this->SetPurchaseMode(); });
	AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });

}


void ShopScene::Purchase()
{
	this->shop->PurchaseItem(cursor, 1);
	renderer->ClearSprite();
	ShowGoldPannel();
	DisplayShopItems();
	ShowCursor();

}

void ShopScene::Sell()
{
	this->shop->SellItem(cursor, 1);
	renderer->ClearSprite();
	ShowGoldPannel();
	DisplayShopItems();
	ShowInventory();
	ShowCursor();
}



void ShopScene::DisplayShopItems()
{
	string healthPotionPath = "drawable/Item/HealthPotion.bmp";
	string laudanumPath = "drawable/Item/Laudanum.bmp";
	string damageBoostPath = "drawable/Item/DamageBoost.bmp";
	
	Vector2d healthPotionPos = { 260, 0 };
	Vector2d laudanumPos = { 299, 0 };
	Vector2d damageBoostPos = { 338, 0 };

	Sprite* healthPotionSprite = new Sprite(healthPotionPath, healthPotionPos, 34, 67);
	Sprite* laudanumSprite = new Sprite(laudanumPath, laudanumPos, 34, 67);
	Sprite* damageBoostSprite = new Sprite(damageBoostPath, damageBoostPos, 34, 67);

	renderer->AddSprite(healthPotionSprite);
	renderer->AddSprite(laudanumSprite);
	renderer->AddSprite(damageBoostSprite);

	Item* healthPotion = new HealthPotion();
	Item* damageboost = new DamageBoost();
	Item* laudanum = new Laudanum();

	renderer->DrawNumber(healthPotion->GetPrice(), { healthPotionPos.x + 10, healthPotionPos.y + 68 }, 15, 33);
	renderer->DrawNumber(damageboost->GetPrice(), { damageBoostPos.x + 10, damageBoostPos.y + 68 }, 15, 33);
	renderer->DrawNumber(laudanum->GetPrice(), { laudanumPos.x + 10, laudanumPos.y + 68 }, 15, 33);
}








