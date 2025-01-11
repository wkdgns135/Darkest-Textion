#pragma once

#include "Character/Monster/Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int dungeonlevel);
	~Goblin() override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:

};