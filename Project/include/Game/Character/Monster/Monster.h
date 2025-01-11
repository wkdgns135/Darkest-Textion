#pragma once
#include "Character/Character.h"
#include "Item/Item.h"
#include "GameManager.h"
#include <iostream>
#include <random>

class Monster abstract : public Character
{
public:
    //TODO : 몬스터 생성할 때 던전 난이도 값을 주어야 함. 0~3 /// 적 스탯이 캐릭터 레벨에 기반하므로 플레이어 레벨도 받아야 함.
    Monster(int dungeonLevel);
    virtual ~Monster() = 0;
    //virtual string GetName() const = 0;
    inline string GetName() const { return name; } // 모두 Name 이라는 값을 반환하는 같은 동작 하므로 순수 가상함수, 가상함수로 사용하지 않음
    virtual Item* DropItem(); // Logic for item drop
    virtual void Hit(int damage) override;
    virtual void Attack() override;
    virtual void Die();
    virtual void TestPrint();

protected:
    int DungeonLevel;
    int PlayerLevel;
    int Rank;

    int AvoidRate;
    int HitRate;

    int MinDropValue;
    int ArtifactRate;
    int MaxItemRank;
    int MaxItemCount;

    Player* APlayer;

    virtual void Magnification();
    int GetRandomValue(int min, int max);
    void InitializeByDungeonLevel();
};