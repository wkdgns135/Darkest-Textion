#pragma once
#include <iostream>
#include <random>
#include "Character/Character.h"
#include "Item/Item.h"
#include "GameManager.h"

class Player;

class Monster abstract : public Character
{
public:
    //TODO : 몬스터 생성할 때 던전 난이도 값을 주어야 함. 0~3 /// 적 스탯이 캐릭터 레벨에 기반하므로 플레이어 레벨도 받아야 함.
    Monster(int dLevel);
    virtual ~Monster() = 0;
    inline string GetName() const { return name; } // 모두 Name 이라는 값을 반환하는 같은 동작 하므로 순수 가상함수, 가상함수로 사용하지 않음
    virtual Item* DropItem(); // Logic for item drop
    virtual void Hit(int damage) override;
    virtual void Attack() override;
    virtual void Die();
    virtual void TestPrint();

protected:
    int dungeonLevel;
    int playerLevel;
    int rank;
    int realDamage;

    int avoidRate;
    int hitRate;

    int minDropValue;
    int artifactRate;
    int maxItemRank;
    int maxItemCount;

    int coolDown1;
    int coolDown2;
    int coolDown3;

    Player* player;

    virtual void Magnification();
    virtual void InitializeByDungeonLevel();
    virtual void NormalAttack() = 0;
    virtual void FirstSkillAttack();
    virtual void SecondSkillAttack();
    virtual void FinalSkillAttack();
    int GetRandomValue(int min, int max);
};