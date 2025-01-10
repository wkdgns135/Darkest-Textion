#pragma once
#include "Consumable.h"

class DamageBoost : Consumable {
private:
	virtual string GetName() const override;
public:
	DamageBoost();
	virtual void Use(Player& Player);
};