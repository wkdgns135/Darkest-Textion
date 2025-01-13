#pragma once
#include "Consumable.h"

class HealthPotion : public Consumable {
public:
	HealthPotion();
	inline virtual string GetName() const override { return name; };
	virtual void Use(Player& Player) override;
};