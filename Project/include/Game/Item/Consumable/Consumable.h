#include "Item/Item.h"
#include "Character/Player/Player.h"

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