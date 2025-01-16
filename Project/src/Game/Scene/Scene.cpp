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

	renderer->DrawNumber(1234/*player->GetGold()*/, { goldPannelLoc.x + 55, goldPannelLoc.y + 5 }, 20, 35);
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
	renderer->RemoveSprite();
	ShowCursor();

}

void Scene::ShowCursor()
{
	Sprite* sprite = new Sprite("drawable/Item/cursor.bmp", cursorLoc[cursor], 35, 65);
	renderer->AddSprite(sprite);
}

