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
	cout << "������ �����ϼ̽��ϴ�.\n 1. ���� ���� Ȯ��\n 2. ����\n 3. �κ��丮 Ȯ��\n 4. �Ǹ�\n";
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
	cout << "������ ���ǹ�ȣ: ";
	cin >> itemIdx;
	cout << "����: ";
	cin >> count;
	shop->PurchaseItem(itemIdx, count);
}

void ShopScene::ShowSellInterface()
{
	int itemIdx;
	int count;
	Player* player = new Player("Tester");
	cin.ignore(10);
	cout << "�Ǹ��� ���ǹ�ȣ: ";
	cin >> itemIdx;
	cout << "����: ";
	cin >> count;

}