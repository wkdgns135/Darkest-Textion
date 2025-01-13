#pragma once

#include "Character/Monster/Monster.h"

class Troll : public Monster
{
public:
	Troll(int dLevel);
	~Troll() override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:
	int skill2Counter;

	void InitializeByDungeonLevel() override;
	void NormalAttack() override;
	void FirstSkillAttack() override;
	void SecondSkillAttack() override;
	void FinalSkillAttack() override;
};