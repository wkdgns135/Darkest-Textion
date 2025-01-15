#pragma once
#include "Scene.h"
#include "Shop/Shop.h"


class ShopScene : public Scene {
private:
	unique_ptr<Shop> shop;
	int inventorySpriteCount;
	bool inventoryFlag;

	void OpenInventory();
	void CloseInventory();
	void DisplayShopItems();
public:
	ShopScene();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void InventoryTrigger();
};