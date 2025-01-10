#include "Item/Consumable/Antivenom.h"
#include "Character/Player/Player.h"

Antivenom::Antivenom()
{
	name = "Antivenom";
	price = 5.f;
}

string Antivenom::GetName() const
{
	return name;
}

void Antivenom::Use(Player& player)
{
	//HERE : player가 중독상태를 해제하도록
	//player.Decipher();
	return;
}