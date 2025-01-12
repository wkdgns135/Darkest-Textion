#pragma once

#include "Character/Monster/Monster.h"

class BossMonster : public Monster
{

public:
    BossMonster(int dungeonlevel);
    ~BossMonster() override;
    Item* DropItem() override;
    void Hit(int damage) override;
    void Attack() override;
    void Die() override;
    
private:
    int Skill3Counter;
    int Skill2Counter;
    int Skill1Counter;
    int CurrentAvoidRate;
    float GetDamageRate;

    void Magnification() override;
    void InitializeByDungeonLevel() override;
    void NormalAttack() override;
    void FirstSkillAttack() override;
    void SecondSkillAttack() override;
    void FinalSkillAttack() override;
};