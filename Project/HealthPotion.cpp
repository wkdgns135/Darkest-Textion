#include "HealthPotion.h"
#include "Player.h"

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	amount = 10.f;
	price = 5.f;
}

string HealthPotion::GetName() const
{
	return name;
}

void HealthPotion::Use(Player& Player)
{
	//HERE : player의 체력 올려주기
	//Player.Heal(amount);
	return;
}