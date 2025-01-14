#pragma once
#include "Scene.h"
#include "Shop/Shop.h"


class ShopScene : public Scene {
private:
	unique_ptr<Shop> shop;
	Sprite *holywater;

	void ShowPurchaseInterface();
	void ShowSellInterface();
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};