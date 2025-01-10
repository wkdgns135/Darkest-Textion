#pragma once
#include "Consumable.h"

class HealthPotion : Consumable {
private:
	virtual string GetName() const override;
public:
	HealthPotion();
	virtual void Use(Player& Player);
};