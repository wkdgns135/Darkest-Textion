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

void ShopScene::ShowInventory() 
{
	//Render Inventory frame
	string invenImage = "drawable/background/Inventory.bmp";
	Vector2d invenLoc = { 200, 150 };
	int invenWidth = 300;
	int invenHeight = 150;
	Sprite* sprite = new Sprite(invenImage, invenLoc, invenWidth, invenHeight);
	renderer->AddSprite(sprite);


	//Player* player = GameManager::GetInstance().GetPlayer();
	//map<string, Inventory> inventory = player->GetItem();

	Item* healthPotion = new HealthPotion();
	Item* damageboost = new DamageBoost();
	Item* laudanum = new Laudanum();
	unique_ptr<Artifact> item = make_unique<HealthStone>();
	Item* healthStone = new RareArtifact(move(item));
	Item* knightsCrest = new KnightsCrest();
	Item* snakeOil = new SnakeOil();
	Item* expStone = new ExpStone();

	map<string, Inventory> inventory = {
		{healthPotion->GetName(), Inventory(healthPotion,3)},
		{damageboost->GetName(), Inventory(damageboost,2)},
		{laudanum->GetName(), Inventory(laudanum,4)},
		{healthStone->GetName(), Inventory(healthStone,3)},
		{expStone->GetName(), Inventory(expStone,3)},
		{"1", Inventory(healthPotion,3)},
		{"2", Inventory(laudanum,3)},
		{"3", Inventory(healthPotion,3)},
		{"4", Inventory(laudanum,3)},
		{"5", Inventory(healthPotion,3)},
		{"6", Inventory(laudanum,3)},
		{"7", Inventory(healthPotion,3)},
		{"8", Inventory(laudanum,3)},
		{"9", Inventory(healthPotion,3)},
		{"10", Inventory(laudanum,3)},
	};

	cursorLoc.clear();

	//Render Inventory Item
	int i = 0;
	int xPadding = 4;
	int yPadding = 4;
	Vector2d itemInitalLoc = { invenLoc.x + xPadding + 6, invenLoc.y + yPadding};
	for (auto item: inventory)
	{
		string itemImage = item.second.GetItem()->GetImagePath();
		int itemWidth = invenWidth / 7 - xPadding*2 ;
		int itemHeight = invenHeight / 2 - yPadding*2;
		Vector2d itemLoc = { itemInitalLoc.x + itemWidth*(i%8) + xPadding*2, itemInitalLoc.y + (i/8 > 0 ? itemHeight + yPadding*2 : 0)};
		Sprite* sprite = new Sprite(itemImage, itemLoc, itemWidth, itemHeight);
		renderer->AddSprite(sprite);
		cursorLoc.push_back(itemLoc);
		renderer->DrawNumber(item.second.GetCount(), { itemLoc.x + 2, itemLoc.y }, 10, 30);
		i++;
	}
}


void ShopScene::ShowGoldPannel()
{
	Player* player = GameManager::GetInstance().GetPlayer();
	string goldPannel = "drawable/Item/Gold.bmp";
	Vector2d goldPannelLoc = { 20, 250 };
	int goldPannelWidth = 120;
	int goldPannelHeight = 40;
	Sprite* sprite = new Sprite(goldPannel, goldPannelLoc, goldPannelWidth, goldPannelHeight);
	renderer->AddSprite(sprite);

	renderer->DrawNumber(1234/*player->GetGold()*/, {goldPannelLoc.x + 55, goldPannelLoc.y + 5}, 20, 35);
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

	AddInputEvent(EKeyEvent::Key_1, [this]() { this->MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { this->MoveCursor(1); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() { this->shop->PurchaseItem(cursor, 1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { this->SetSellMode(); });
	

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

	AddInputEvent(EKeyEvent::Key_1, [this]() { this->MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { this->MoveCursor(1); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() { this->shop->SellItem(cursor, 1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { this->SetPurchaseMode(); });

}


void ShopScene::MoveCursor(int direction)
{
	if (direction > 0)
	{
		if (cursor >= cursorLoc.size() - 1) return;
		else cursor++;
	}
	else
	{
		if (cursor <= 0) return;
		else cursor--;
	}
	renderer->RemoveSprite();
	ShowCursor();

}

void ShopScene::ShowCursor()
{
	Sprite* sprite = new Sprite("drawable/Item/cursor.bmp", cursorLoc[cursor], 35, 65);
	renderer->AddSprite(sprite);
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

	


	renderer->DrawNumber(healthPotion->GetPrice(), { healthPotionPos.x + 10, healthPotionPos.y + 68 }, 10, 30);
	renderer->DrawNumber(damageboost->GetPrice(), { damageBoostPos.x + 10, damageBoostPos.y + 68 }, 10, 30);
	renderer->DrawNumber(laudanum->GetPrice(), { laudanumPos.x + 10, laudanumPos.y + 68 }, 10, 30);
}