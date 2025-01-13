#pragma once
#include "Consumable.h"

class Laudanum : public Consumable {
private:
public:
	Laudanum();
	inline virtual string GetName() const override { return name; };
	virtual void Use(Player& player) override;
};