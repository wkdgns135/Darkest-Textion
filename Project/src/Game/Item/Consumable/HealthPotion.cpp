#include "Item/Consumable/HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	price = 5;
	amount = 10;
	imagePath = "drawable/Item/HealthPotion.bmp";
}

void HealthPotion::Use(Player& player)
{
	player.AddCurrentHealth(amount);
	return;
}