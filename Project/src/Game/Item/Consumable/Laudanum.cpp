#include "Item/Consumable/Laudanum.h"

Laudanum::Laudanum()
{
	name = "Laudanum";
	price = 5;
	amount = 10;
	imagePath = "drawable/Item/Laudanum.bmp";

}

void Laudanum::Use(Player& Player)
{
	//HERE : player의 스트레스 줄이기
	//player.[스트레스줄이기](amount);
	return;
}