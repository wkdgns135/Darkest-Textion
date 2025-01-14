#include "Character/Player/Player.h"

//아이템 클래스
#include "Item/Item.h"
#include "Item/Artifact/SpeedStone.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/ExpStone.h"

#pragma once

using namespace std;

class Shop
{
private:
	Player* player;
	SpeedStone speedstone;
	SnakeOil snake0il;
	KnightsCrest knightscrest;
	HealthStone healthstone;
	ExpStone expstone;
 	map<string, Item> itemlist;
	string prefix = "[ 상점 ] ";

	//검사 함수
	int GetInventorySize();
	bool IsPlayerItemAvailable(int index);

public:
	Shop(Player* player);
	void PurchaseItem(int index, int gold, int count);
	void SellItem(int index, int count);
	void ShowItemList();

};
