#include "Item/Consumable/DamageBoost.h"

DamageBoost::DamageBoost()
{
	name = "DamageBoost";
	price = 5;
	amount = 5;
	duration = 5.f;
	imagePath = "drawable/Item/DamageBoost.bmp";
}

void DamageBoost::Use(Player& player)
{
	player.AddDamage(amount);
	return;
}