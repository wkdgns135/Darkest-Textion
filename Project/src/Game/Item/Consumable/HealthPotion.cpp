#include "Item/Consumable/HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	price = 10;
	amount = 30;
	imagePath = "drawable/Item/HealthPotion.bmp";
}

void HealthPotion::Use(Player& player)
{
	player.AddCurrentHealth(amount);
	return;
}