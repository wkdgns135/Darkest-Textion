#include "Item/Consumable/HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	price = 5;
	amount = 10;
}

void HealthPotion::Use(Player& player)
{
	player.AddHealth(amount);
	return;
}