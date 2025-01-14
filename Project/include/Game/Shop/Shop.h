#pragma once
#include "Character/Player/Player.h"

//아이템 클래스
#include "Item/Item.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/ExpStone.h"

#include <vector>
#include <map>
#include <memory>

#pragma once

using namespace std;

class Shop
{
	private:
 		map<string, Item*> itemlist;
		string prefix = "[ 상점 ] ";

		//검사 함수
		int GetInventorySize();
		bool IsPlayerItemAvailable(int index);

	public:
		Shop();
		void RandomItemInitalize();
		void OnlyConsumableInitialize();
		void PurchaseItem(int index, int count);
		void SellItem(int index, int count);
		void ShowItemList();

};
