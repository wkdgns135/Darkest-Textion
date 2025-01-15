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

using namespace std;

void ShopScene::Enter()
{
	shop = make_unique<Shop>();
	shop->InitializeOnlyConsumable();


	renderer->AddBackground("drawable/background/ShopBackground.bmp");
	//renderer->AddBackground("drawable/background/Picture6.bmp");
	//for (int i = 0; i < 3; i++)
	//{
	//	string path = shop->GetItem(i)->GetImagePath();
	//	Vector2d pos = { 50, 50 };
	//	Sprite* sprite = new Sprite(path, pos, 50, 50);
	//	renderer->AddSprite(sprite);
	//}
	

	ShowInventory();

	//string path = shop->GetItem(1)->GetImagePath();
	//Vector2d pos = { 200, 150 };
	//Sprite* sprite = new Sprite("drawable/background/Inventory.bmp", pos, 300, 150);
	//renderer->AddSprite(sprite);

	//string path1 = shop->GetItem(1)->GetImagePath();
	//Vector2d pos1 = { 200, 150 };
	//Sprite* sprite1 = new Sprite("drawable/Item/HealthPotion.bmp", pos1, 50, 50);
	//renderer->AddSprite(sprite1);


	//OutputManager::GetInstance().PrintAsciiArt(MainAsciiArt);
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	//AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	//renderer->SetConsoleFontForText();
	//cout << "상점에 입장하셨습니다.\n 1. 상점 물건 확인\n 2. 구매\n 3. 인벤토리 확인\n 4. 판매\n";
	//AddInputEvent(EKeyEvent::Key_1, [this]() {this->shop->ShowItemList(); });
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

void ShopScene::ShowPurchaseInterface()
{
	int itemIdx;
	int count;
	Player* player = new Player("Tester");
	cout << "구매할 물건번호: ";
	cin >> itemIdx;
	cout << "개수: ";
	cin >> count;
	shop->PurchaseItem(itemIdx, count);
}

void ShopScene::ShowSellInterface()
{
	int itemIdx;
	int count;
	Player* player = new Player("Tester");
	cin.ignore(10);
	cout << "판매할 물건번호: ";
	cin >> itemIdx;
	cout << "개수: ";
	cin >> count;

}

void ShopScene::ShowInventory() const
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
		//{healthPotion->GetName(), Inventory(healthPotion,3)},
		{damageboost->GetName(), Inventory(damageboost,2)},
		{laudanum->GetName(), Inventory(laudanum,4)},
		//{healthStone->GetName(), Inventory(healthStone,3)},
		//{expStone->GetName(), Inventory(expStone,3)}
	};


	//Render Inventory Item
	int i = 0;
	for (auto item: inventory)
	{
		string itemImage = item.second.GetItem()->GetImagePath();
		int itemWidth = invenWidth / 7;
		int itemHeight = invenHeight / 2;
		Vector2d itemLoc = { invenLoc.x + (itemHeight * i), invenLoc.y + (itemWidth * i) };
		Sprite* sprite = new Sprite(itemImage, invenLoc, itemWidth, itemHeight);
		renderer->AddSprite(sprite);
		i++;
	}

}