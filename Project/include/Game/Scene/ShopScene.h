#pragma once
#include "Scene.h"
#include "Shop/Shop.h"


class ShopScene : public Scene {
private:
	unique_ptr<Shop> shop;
	vector<Vector2d> cursorLoc;
	int cursor;

	void SetPurchaseMode();
	void SetSellMode();


	void DisplayShopItems();
	void ShowGoldPannel();
	void ShowInventory();
	void ShowCursor();
	void MoveCursor(int direction);
public:
	ShopScene();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void Purchase();
	void Sell();
};