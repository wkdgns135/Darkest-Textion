#pragma once
#include "Consumable.h"

class Laudanum : Consumable {
private:
	virtual string GetName() const override;
public:
	Laudanum();
	virtual void Use(Player& Player) override;
};