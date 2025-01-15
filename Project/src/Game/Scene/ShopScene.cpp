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

	//background
	renderer->AddBackground("drawable/background/ShopBackground2.bmp");

	DisplayShopItems();

	//goldPannel
	Player* player = GameManager::GetInstance().GetPlayer();
	string goldPannel = "drawable/Item/Gold.bmp";
	//string goldPannel = "drawable/number/1.bmp";
	Vector2d goldPannelLoc = { 20, 250 };
	int goldPannelWidth = 120;
	int goldPannelHeight = 40;
	Sprite* sprite = new Sprite(goldPannel, goldPannelLoc, goldPannelWidth, goldPannelHeight);
	renderer->AddSprite(sprite);

	//HERE : player 연결 시 바꾸기
	//PrintNumber(renderer, player->GetGold(), { goldPannelLoc.x + 55, goldPannelLoc.y + 5 });
	PrintNumber(renderer, 12354, {goldPannelLoc.x + 55, goldPannelLoc.y + 5});


	//bind Input
	AddInputEvent(EKeyEvent::Key_1, [this]() { this->InventoryTrigger(); });
	//AddInputEvent(EKeyEvent::Key_2, [this]() {this->ShowPurchaseInterface(); });
	////AddInputEvent(EKeyEvent::Key_3, []() {	GameManager::GetInstance().GetPlayer()->ShowInventory(); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() {this->ShowSellInterface(); });

	//item Input
	//AddInputEvent(EKeyEvent::Key_1, [this]() { shop->PurchaseItem(1, 1); });
	//AddInputEvent(EKeyEvent::Key_2, [this]() { shop->PurchaseItem(2, 1); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() { shop->PurchaseItem(3, 1); });
	//AddInputEvent(EKeyEvent::Key_1, [this]() { shop->SellItem(1, 1); });
	//AddInputEvent(EKeyEvent::Key_2, [this]() { shop->SellItem(2, 1); });
	//AddInputEvent(EKeyEvent::Key_3, [this]() { shop->SellItem(3, 1); });
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
		inventorySpriteCount += PrintNumber(renderer, item.second.GetCount(), { itemLoc.x + 2, itemLoc.y + 2 }, { 7, 15 });
		inventorySpriteCount++;
		i++;
	}
}

void ShopScene::CloseInventory() {
	for (int i = 0; i < inventorySpriteCount; i++)
	{
		renderer->ClearSprite();
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

// 새로운 함수 추가: 상점 아이템들을 화면에 표시
void ShopScene::DisplayShopItems()
{
	// 아이템 이미지 경로 정의
	string healthPotionPath = "drawable/Item/HealthPotion.bmp";
	string laudanumPath = "drawable/Item/Laudanum.bmp";
	string damageBoostPath = "drawable/Item/DamageBoost.bmp";

	// 각 아이템의 위치 정의 (우측 상단)
	Vector2d healthPotionPos = { 260, 0 };
	Vector2d laudanumPos = { 299, 0 };
	Vector2d damageBoostPos = { 338, 0 };

	// 스프라이트 생성 및 렌더러에 추가
	Sprite* healthPotionSprite = new Sprite(healthPotionPath, healthPotionPos, 34, 67);
	Sprite* laudanumSprite = new Sprite(laudanumPath, laudanumPos, 34, 67);
	Sprite* damageBoostSprite = new Sprite(damageBoostPath, damageBoostPos, 34, 67);

	renderer->AddSprite(healthPotionSprite);
	renderer->AddSprite(laudanumSprite);
	renderer->AddSprite(damageBoostSprite);

	// 아이템의 가격 가져오기
	Item* healthPotion = new HealthPotion();
	Item* damageboost = new DamageBoost();
	Item* laudanum = new Laudanum();

	PrintNumber(renderer, healthPotion->GetPrice(), { healthPotionPos.x + 10, healthPotionPos.y + 68 });
	PrintNumber(renderer, damageboost->GetPrice(), { laudanumPos.x + 10, laudanumPos.y + 68 });
	PrintNumber(renderer, laudanum->GetPrice(), { damageBoostPos.x + 10, damageBoostPos.y + 68 });
}