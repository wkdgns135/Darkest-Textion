#include "Laudanum.h"
#include "Player.h"

Laudanum::Laudanum()
{
	name = "Laudanum";
	amount = 10.f;
	price = 5.f;
}

string Laudanum::GetName() const
{
	return name;
}

void Laudanum::Use(Player& Player)
{
	//HERE : player의 스트레스 줄이기
	//player.[스트레스줄이기](amount);
	return;
}