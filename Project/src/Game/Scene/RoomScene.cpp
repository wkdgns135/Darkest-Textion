#include "Scene/RoomScene.h"
#include "GameManager.h"
#include "Scene/SceneManager.h"
#include "Utility.h"

void RoomScene::ChooseMode()
{
	renderer->ClearSprite();
	ClearEvent();

	Sprite* retreat = new Sprite("drawable/Ui/Retreat.bmp", { 0, 120 }, 100, 50);
	Sprite* nextRoom = new Sprite("drawable/Ui/NextRoom.bmp", { 400, 120 }, 100, 50);
	Sprite* inventorySprite = new Sprite("drawable/Ui/Inventory.bmp", { 375, 200 }, 75, 100);
	renderer->AddSprite(inventorySprite);
	renderer->AddSprite(retreat);
	renderer->AddSprite(nextRoom);
	UpdateNumber();

	AddInputEvent(Key_1, [this]() {NextRoom(); });
	AddInputEvent(Key_I, [this]() {InventoryMode(); });
	AddInputEvent(Key_ESC, [this]() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
}

void RoomScene::InventoryMode()
{
	ClearEvent();
	renderer->ClearSprite();

	ShowInventory();
	cursor = 0;
	UpdateNumber();
	ShowCursor();

	AddInputEvent(EKeyEvent::Key_1, [this]() { this->MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { this->MoveCursor(1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { this->UseItem(); });
	AddInputEvent(EKeyEvent::Key_I, [this]() { this->ChooseMode(); });
	AddInputEvent(EKeyEvent::Key_ESC, [this]() { this->ChooseMode(); });
}


void RoomScene::UpdateNumber()
{
	renderer->DrawNumber(player->GetCurrentHealth(), { 50, 10 }, 25, 50);
	renderer->DrawNumber(player->GetStress(), { 150, 10 }, 25, 50);
	renderer->DrawNumber(player->GetDamage(), { 250, 10 }, 25, 50);
}

void RoomScene::NextRoom()
{
	int proba = GetRandomValue(0, 100);
	GameManager::GetInstance().IncreaseFloor();
	switch (GameManager::GetInstance().GetCurrentDungeon())
	{
		case Weald: break;
		case Cove: proba * 0.8; break;
		case DarkestDungeon: proba * 0.6; break;
	}
	if (proba < 10) {
		//TODO: ITEM 방
		//SceneManager::GetInstance().ChangeScene<>()
	}
	else if (proba < 30) {
		//TODO: 기믹 방
		
	}
	else {
		SceneManager::GetInstance().ChangeScene<BattleScene>();
	}
}

void RoomScene::Enter()
{
	DungeonScene::Enter();
	player = GameManager::GetInstance().GetPlayer();
	Sprite* Hp = new Sprite("drawable/Ui/HP.bmp", { 0, 10 }, 50, 50);
	Sprite* Str = new Sprite("drawable/Ui/STR.bmp", { 100, 10 }, 50, 50);
	Sprite* Dmg = new Sprite("drawable/Ui/Dmg.bmp", { 200, 10 }, 50, 50);

	renderer->AddFixSprite(Hp);
	renderer->AddFixSprite(Dmg);
	renderer->AddFixSprite(Str);
	UpdateNumber();
	ChooseMode();
}

void RoomScene::UseItem()
{
	auto& inventory = player->GetItem();
	auto it = inventory.begin(); //리스트 첫번째 칸
	advance(it, cursor); //index만큼 뒤로 이동
	player->UseItem(it->first);
	UpdateNumber();
	ShowInventory();
	ShowCursor();
}

void RoomScene::Update()
{
}

void RoomScene::Exit()
{
}
