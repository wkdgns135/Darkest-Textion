#pragma once

#include "Character/Monster/Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int dLevel);
	~Goblin() override;
	Item* DropItem() override;
	void Hit(int damage) override;
	void Attack() override;
	void Die() override;

private:
	void InitializeByDungeonLevel() override;
	void NormalAttack() override;
	void FirstSkillAttack() override;
	void SecondSkillAttack() override;
	void FinalSkillAttack() override;
};