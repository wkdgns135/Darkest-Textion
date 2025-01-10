#include "Item/Consumable/DamageBoost.h"

DamageBoost::DamageBoost()
{
	name = "DamageBoost";
	amount = 5.f;
	price = 5.f;
}

string DamageBoost::GetName() const
{
	return name;
}

void DamageBoost::Use(Player& Player)
{
	//HERE : player의 데미지 올려주기
	//Player.Damage(amount);
	return;
}