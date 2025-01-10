#pragma once

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int dungeonlevel, int playerLevel);
	~Goblin() override;
	//string GetName() const override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:

};