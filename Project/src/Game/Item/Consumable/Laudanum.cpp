#include "Item/Consumable/Laudanum.h"
#include "Character/Player/Player.h"

Laudanum::Laudanum()
{
	name = "Laudanum";
	price = 10;
	amount = 10;
	imagePath = "drawable/Item/Laudanum.bmp";

}

void Laudanum::Use(Player& player)
{
	if(player.GetStress() - amount >= 0) player.AddStress(-amount);
	return;
}