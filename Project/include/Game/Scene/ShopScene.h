#pragma once
#include "Scene.h"
#include "Shop/Shop.h"


class ShopScene : public Scene {
private:
	unique_ptr<Shop> shop;

	void SetPurchaseMode();
	void SetSellMode();


	void DisplayShopItems();
public:
	ShopScene();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void Purchase();
	void Sell();
	void MoveCursor(int direction) override;
};