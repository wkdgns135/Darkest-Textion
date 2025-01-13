#pragma once

#include "Character/Monster/Monster.h"

class BossMonster : public Monster
{

public:
    BossMonster(int dLevel);
    ~BossMonster() override;
    Item* DropItem() override;
    void Hit(int damage) override;
    void Attack() override;
    void Die() override;
    
private:
    int skill3Counter;
    int skill2Counter;
    int skill1Counter;
    int currentAvoidRate;
    float getDamageRate;

    void Magnification() override;
    void InitializeByDungeonLevel() override;
    void NormalAttack() override;
    void FirstSkillAttack() override;
    void SecondSkillAttack() override;
    void FinalSkillAttack() override;
};