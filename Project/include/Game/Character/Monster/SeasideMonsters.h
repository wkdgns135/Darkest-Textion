#pragma once

#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterActionHandle.h"

class SeasideMonsterPelagic : public Monster
{

public:
    SeasideMonsterPelagic();
    ~SeasideMonsterPelagic() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class SeasideMonsterStinger : public Monster
{
public:
    SeasideMonsterStinger();
    ~SeasideMonsterStinger() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class SeasideMonsterThrall : public Monster
{
public:
    SeasideMonsterThrall();
    ~SeasideMonsterThrall() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};