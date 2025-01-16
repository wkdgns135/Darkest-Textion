#include <Windows.h>
#include "Scene/Scene.h"
#include "Item/Item.h"
#include "GameManager.h"
#include "Character/Player/Player.h"

Scene::Scene()
{
	inputEvent = make_unique<InputEvent>();
	renderer = make_unique<Renderer>();
}

Scene::~Scene()
{
	
}

void Scene::RootUpdate()
{
	while (isActive) {
		renderer->ClearBuffer();
		renderer->FillBuffer(deltaTime);
		renderer->Render();
		inputEvent->ProcessEvents();
		Update();
		Sleep(deltaTime); // Frame
	}
}


void Scene::RootEnter()
{
	isActive = true;
}

void Scene::RootExit()
{
	isActive = false;
	renderer->ClearSprite();
	system("cls");
}


void Scene::ShowInventory()
{
	//Render Inventory frame
	string invenImage = "drawable/background/Inventory.bmp";
	Vector2d invenLoc = { 200, 150 };
	int invenWidth = 300;
	int invenHeight = 150;
	Sprite* sprite = new Sprite(invenImage, invenLoc, invenWidth, invenHeight);
	renderer->AddSprite(sprite);


	Player* player = GameManager::GetInstance().GetPlayer();
	map<string, Inventory> inventory = player->GetItem();

	cursorLoc.clear();

	//Render Inventory Item
	int i = 0;
	int xPadding = 4;
	int yPadding = 4;
	Vector2d itemInitalLoc = { invenLoc.x + xPadding + 6, invenLoc.y + yPadding };
	for (auto &item : inventory)
	{
		string itemImage = item.second.GetItem()->GetImagePath();
		int itemWidth = invenWidth / 7 - xPadding * 2;
		int itemHeight = invenHeight / 2 - yPadding * 2;
		Vector2d itemLoc = { itemInitalLoc.x + itemWidth * (i % 8) + xPadding * 2, itemInitalLoc.y + (i / 8 > 0 ? itemHeight + yPadding * 2 : 0) };
		Sprite* sprite = new Sprite(itemImage, itemLoc, itemWidth, itemHeight);
		renderer->AddSprite(sprite);
		cursorLoc.push_back(itemLoc);
		renderer->DrawNumber(item.second.GetCount(), { itemLoc.x + 2, itemLoc.y }, 10, 30);
		i++;
	}
	if (cursorLoc.empty())cursorLoc.push_back(itemInitalLoc);
	ShowEquipPannel(invenLoc);
}

void Scene::ShowGoldPannel()
{
	Player* player = GameManager::GetInstance().GetPlayer();
	string goldPannel = "drawable/Item/Gold.bmp";
	Vector2d goldPannelLoc = { 20, 250 };
	int goldPannelWidth = 120;
	int goldPannelHeight = 40;
	Sprite* sprite = new Sprite(goldPannel, goldPannelLoc, goldPannelWidth, goldPannelHeight);
	renderer->AddSprite(sprite);

	renderer->DrawNumber(player->GetGold(), { goldPannelLoc.x + 55, goldPannelLoc.y + 5 }, 20, 35);
}

void Scene::ShowEquipPannel(Vector2d initLoc)
{
	string equipImage = "drawable/background/EquipPannel.bmp";
	int equipWidth = 100;
	int equipHeight = 75;
	Vector2d equipLoc = { 500 - equipWidth, initLoc.y - equipHeight };
	Sprite* sprite = new Sprite(equipImage, equipLoc, equipWidth, equipHeight);
	renderer->AddSprite(sprite);

	Player* player = GameManager::GetInstance().GetPlayer();
	map<string, Inventory> inventory = player->GetEquip();

	equipCursorLoc.clear();
	int i = 0;
	int xPadding = 4;
	int yPadding = 4;
	Vector2d itemInitalLoc = { equipLoc.x + xPadding + 6, equipLoc.y + yPadding };
	for (auto& item : inventory)
	{
		string itemImage = item.second.GetItem()->GetImagePath();
		int itemWidth = equipWidth / 2 - xPadding * 2;
		int itemHeight = equipHeight / 1 - yPadding * 2;
		Vector2d itemLoc = { itemInitalLoc.x + itemWidth * (i % 8) + xPadding * 2, itemInitalLoc.y + (i / 8 > 0 ? itemHeight + yPadding * 2 : 0) };
		Sprite* sprite = new Sprite(itemImage, itemLoc, itemWidth, itemHeight);
		renderer->AddSprite(sprite);
		equipCursorLoc.push_back(itemLoc);
		i++;
	}
	if (equipCursorLoc.empty()) equipCursorLoc.push_back(itemInitalLoc);
}


void Scene::MoveCursor(int direction)
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
	RedrawInventory();
}

void Scene::ShowCursor()
{
	Sprite* sprite = new Sprite("drawable/Item/cursor.bmp", cursorLoc[cursor], 35, 65);
	renderer->AddSprite(sprite);
}

void Scene::MoveEquipCursor(int direction)
{
	if (direction > 0)
	{
		if (equipCursur >= equipCursorLoc.size() - 1) return;
		else equipCursur++;
	}
	else
	{
		if (equipCursur <= 0) return;
		else equipCursur--;
	}
	RedrawInventory();
}
void Scene::ShowEquipCursor()
{
	Sprite* sprite = new Sprite("drawable/Item/cursor.bmp", equipCursorLoc[equipCursur], 35, 65);
	renderer->AddSprite(sprite);
}

void Scene::RedrawInventory()
{
	renderer->ClearSprite();
	ShowGoldPannel();
	ShowInventory();
	ShowCursor();
	ShowEquipCursor();
}

//inventory가 닫히고 사용할 custom mode를 override해야함
//inventory 열렸을때는 다른씬 이동 불가능
void Scene::SetInventoryMode()
{
	ClearEvent();
	RedrawInventory();
	cursor = 0;
	equipCursur = 0;

	AddInputEvent(EKeyEvent::Key_1, [this]() { MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { MoveCursor(1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() {
		auto& inventory = GameManager::GetInstance().GetPlayer()->GetItem();
		auto it = inventory.begin(); //리스트 첫번째 칸
		advance(it, cursor); //index만큼 뒤로 이동
		GameManager::GetInstance().GetPlayer()->UseItem(it->first);
		});
	AddInputEvent(EKeyEvent::Key_Q, [this]() { MoveEquipCursor(-1); });
	AddInputEvent(EKeyEvent::Key_W, [this]() { MoveEquipCursor(1); });
	AddInputEvent(EKeyEvent::Key_E, [this]() {
		Player* player = GameManager::GetInstance().GetPlayer();
		auto& inventory = player->GetItem();
		auto& equipInventory = player->GetEquip();
		auto it = inventory.begin(); //리스트 첫번째 칸
		auto itEquip = equipInventory.begin();
		advance(it, cursor); //index만큼 뒤로 이동
		advance(itEquip, equipCursur);
		if(itEquip != equipInventory.end())
			player->UnEquipItem(itEquip->first);
		player->EquipItem(it->first);
		});
	AddInputEvent(EKeyEvent::Key_I, [this]() { this->SetCustomMode(); });
}

void Scene::SetCustomMode()
{
	ClearEvent();
	renderer->ClearSprite();
	Sprite* sprite = new Sprite("drawable/Item/cursor.bmp", { 1,1 }, 1, 1);
	renderer->AddSprite(sprite);
}

