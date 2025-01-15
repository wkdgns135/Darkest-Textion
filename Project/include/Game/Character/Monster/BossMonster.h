#pragma once

#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterActionHandle.h"


class BossMonsterHeart : public Monster
{

public:
    BossMonsterHeart();
    ~BossMonsterHeart() override;
    
private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class BossMonsterSiren : public Monster
{
public:
    BossMonsterSiren();
    ~BossMonsterSiren() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class BossMonsterHag : public Monster
{
public:
    BossMonsterHag();
    ~BossMonsterHag() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};