#pragma once

#include "Monster.h"

class BossMonster : public Monster
{

public:
    BossMonster(int dungeonlevel, int playerLevel);
    ~BossMonster() override;
    //string GetName() const override;
    Item* DropItem() override;
    void Hit(int damage) override;
    void Attack() override;
    void Die() override;
    void Magnification() override;

private:
    
};