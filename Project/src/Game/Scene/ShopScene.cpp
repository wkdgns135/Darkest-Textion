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


int PrintNumber(unique_ptr<Renderer>& renderer, int number, Vector2d initLoc, Vector2d size = { 10, 30 }) {
	int addCount = 0;
	
	//문자열로 변환
	string strNum = to_string(number);

	//sprite 추가
	string imagePath = "drawable/number/*.bmp";
	int insertPoint = imagePath.find_first_of("*");
	char a = 'd';
	const char* b = &a;
	int i = 0;
	for (char e : strNum)
	{
		string num = to_string(e - '0');
		string numImage = imagePath.replace(insertPoint, 1, num);
		int numWidth = size.x;
		int numHeight = size.y;
		Vector2d numLoc = { initLoc.x + numWidth * i, initLoc.y };
		Sprite* sprite = new Sprite(numImage, numLoc, numWidth, numHeight);
		renderer->AddSprite(sprite);
		addCount++;
		i++;
	}
	return addCount;
}

ShopScene::ShopScene()
{
	inventorySpriteCount = 0;
	inventoryFlag = false;
}

void ShopScene::Enter()
{
	shop = make_unique<Shop>();
	shop->InitializeOnlyConsumable();


	renderer->AddBackground("drawable/background/ShopBackground2.bmp");

	string goldPannel = "drawable/Item/Gold.bmp";
	//string goldPannel = "drawable/number/1.bmp";
	Vector2d goldPannelLoc = { 20, 250 };
	int goldPannelWidth = 120;
	int goldPannelHeight = 40;
	Sprite* sprite = new Sprite(goldPannel, goldPannelLoc, goldPannelWidth, goldPannelHeight);
	renderer->AddSprite(sprite);

	PrintNumber(renderer, 40, { goldPannelLoc.x + 55, goldPannelLoc .y + 5});


	AddInputEvent(EKeyEvent::Key_1, [this]() { this->InventoryTrigger(); });
	//AddInputEvent(EKeyEvent::Key_2, [this]() {this->ShowPurchaseInterface(); });
	////AddInputEvent(EKeyEvent::Key_3, []() {	GameManager::GetInstance().GetPlayer()->ShowInventory(); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() {this->ShowSellInterface(); });

}

void ShopScene::Update()
{

}

void ShopScene::Exit()
{

}

void ShopScene::OpenInventory() 
{
	//Render Inventory frame
	string invenImage = "drawable/background/Inventory.bmp";
	Vector2d invenLoc = { 200, 150 };
	int invenWidth = 300;
	int invenHeight = 150;
	Sprite* sprite = new Sprite(invenImage, invenLoc, invenWidth, invenHeight);
	renderer->AddSprite(sprite);
	inventorySpriteCount++;


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
		inventorySpriteCount++;
		i++;
	}
}

void ShopScene::CloseInventory() {
	for (int i = 0; i < inventorySpriteCount; i++)
	{
		renderer->RemoveSprite();
	}
	inventorySpriteCount = 0;
}

void ShopScene::InventoryTrigger()
{
	if (inventoryFlag)
	{
		CloseInventory();
	}
	else
	{
		OpenInventory();
	}
	inventoryFlag = (inventoryFlag + 1) % 2;
}

