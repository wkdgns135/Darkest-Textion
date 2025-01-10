#include "Item.h"

class Player;

class Consumable : Item {
protected:
	string name;
	float amount;
	float price;

public:
	virtual ~Consumable() {};
	virtual string GetName() const = 0;
	virtual void Use(Player& Player) = 0;
};