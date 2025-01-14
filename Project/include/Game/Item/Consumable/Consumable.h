#pragma once
#include "Item/Item.h"
#include "Character/Player/Player.h"

class Consumable : public Item {
protected:
	int amount;

public:
	virtual ~Consumable() {};
	virtual void Use(Player& player) = 0;
};