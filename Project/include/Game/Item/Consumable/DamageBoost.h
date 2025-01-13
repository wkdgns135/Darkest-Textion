#pragma once
#include "Consumable.h"

class DamageBoost : public Consumable {
private:
	float duration;
public:
	DamageBoost();
	inline virtual string GetName() const override { return name; };
	virtual void Use(Player& player) override;
};