#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item/Item.h"


class Inventory
{
private:
	Item* item;
	int count;
public:
	Inventory(Item* item, int count) : item(item), count(count) {}
	inline Item* GetItem() const { return item; }
	inline int GetCount() const { return count; }
	inline void AddCount(int num) { count += num; }
};