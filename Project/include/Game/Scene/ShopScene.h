#pragma once
#include "Scene.h"
#include "Shop/Shop.h"


class ShopScene : public Scene {
private:
	unique_ptr<Shop> shop;

	int cursor;
	vector<Vector2d> cursorLoc;
	bool inventoryFlag;

	void ShowGoldPannel();

	void Sell();
	void Purchase();
	void SetPurchaseMode();
	void SetSellMode();
	void MoveCursor(int direction);
	void MoveCursorRight();
public:
	ShopScene();
	void ShowInventory();
	void ShowCursor();
	void CloseInventory();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void InventoryTrigger();
};