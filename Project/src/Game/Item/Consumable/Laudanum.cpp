#include "Item/Consumable/Laudanum.h"
#include "Character/Player/Player.h"

Laudanum::Laudanum()
{
	name = "Laudanum";
	price = 5;
	amount = 10;
	imagePath = "drawable/Item/Laudanum.bmp";

}

void Laudanum::Use(Player& player)
{
	player.AddStress(-amount);
	return;
}