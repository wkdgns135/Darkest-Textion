#pragma once

#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterActionHandle.h"


class DarkestMonsterHorror : public Monster
{
public:
    DarkestMonsterHorror();
    ~DarkestMonsterHorror() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class DarkestMonsterCyst : public Monster
{
public:
    DarkestMonsterCyst();
    ~DarkestMonsterCyst() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class DarkestMonsterTemplar : public Monster
{
public:
    DarkestMonsterTemplar();
    ~DarkestMonsterTemplar() override;

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class DarkestMonsterHound : public Monster
{
public:
    DarkestMonsterHound();
    ~DarkestMonsterHound();

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};

class DarkestMonsterWitch : public Monster
{
public:
    DarkestMonsterWitch();
    ~DarkestMonsterWitch();

private:
    void InitializeByDungeonLevel() override;
    void SetAttackInfo() override;
};