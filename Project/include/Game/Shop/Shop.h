#pragma once
#include "Character/Player/Player.h"

//������ Ŭ����
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
 		map<int, Item*> itemlist;
		string prefix = "[ ���� ] ";

		//�˻� �Լ�
		int GetInventorySize();
		bool IsPlayerItemAvailable(int index);

	public:
		Shop();
		void InitalizeWithRandomItem();
		void InitializeOnlyConsumable();
		void PurchaseItem(int index, int count);
		void SellItem(int index, int count);
		void ShowItemList();
		inline Item* GetItem(int index) const { auto e = itemlist.find(index); return e->second; };

};
