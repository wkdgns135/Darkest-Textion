#pragma once

#include "Monster.h"

class Troll : public Monster
{
public:
	Troll(int dungeonlevel, int playerLevel);
	~Troll() override;
	//string GetName() const override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:
	
};