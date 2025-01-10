#pragma once
#include "Character.h"

class Player : Character {
public:
	Player(string Name);
	virtual void Hit(int Damage) override;
	virtual void Attack() override;
};