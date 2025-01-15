#pragma once

#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterActionHandle.h"


class ForestMonsterFungal : public Monster
{

public:
    ForestMonsterFungal();
    ~ForestMonsterFungal() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class ForestMonsterGiant : public Monster
{
public:
    ForestMonsterGiant();
    ~ForestMonsterGiant() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class ForestMonsterCrone : public Monster
{
public:
    ForestMonsterCrone();
    ~ForestMonsterCrone() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};