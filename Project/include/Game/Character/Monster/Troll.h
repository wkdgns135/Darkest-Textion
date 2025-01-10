#pragma once

#include "Character/Monster/Monster.h"

class Troll : public Monster
{
public:
	Troll(int dungeonlevel, int playerLevel);
	~Troll() override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:
	
};