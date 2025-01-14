#include "Scene/SceneManager.h"
#include "Shop/Shop.h"
#include "Global/ProjectEnum.h"
#include "Global/Global.h"
#include "Character/Player/Player.h"

using namespace std;

void ShopScene::Enter()
{
	shop = make_unique<Shop>();
	//OutputManager::GetInstance().PrintAsciiArt(MainAsciiArt);
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });
	//AddInputEvent(Key_ESC, []() {SceneManager::GetInstance().ChangeScene<TitleScene>(); });
	renderer->SetConsoleFontForText();
	cout << "상점에 입장하셨습니다.\n 1. 상점 물건 확인\n 2. 구매\n 3. 인벤토리 확인\n 4. 판매\n";
	AddInputEvent(EKeyEvent::Key_1, [this]() {this->shop->ShowItemList(); });
	AddInputEvent(EKeyEvent::Key_2, [this]() {this->ShowPurchaseInterface();; });
	//AddInputEvent(EKeyEvent::Key_3, []() {	GameManager::GetInstance().GetPlayer()->ShowInventory(); });
	AddInputEvent(EKeyEvent::Key_3, [this]() {this->ShowSellInterface(); });

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