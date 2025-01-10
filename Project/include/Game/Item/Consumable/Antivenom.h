#pragma once
#include "Consumable.h"

class Antivenom : public Consumable
{
private:
	
public:
	Antivenom();
	virtual string GetName() const override;
	virtual void Use(Player& player) override;
};
