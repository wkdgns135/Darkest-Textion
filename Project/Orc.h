#pragma once

#include "Monster.h"

class Orc : public Monster
{
public:
	Orc(int dungeonlevel, int playerLevel);
	~Orc() override;
	//string GetName() const override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:

};