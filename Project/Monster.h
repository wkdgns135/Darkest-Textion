#pragma once
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <random>

class Monster abstract : public Character
{
public:
    //TODO : 몬스터 생성할 때 던전 난이도 값을 주어야 함. 0~3 /// 적 스탯이 캐릭터 레벨에 기반하므로 플레이어 레벨도 받아야 함.
    Monster(int dungeonLevel, int playerLevel);
    virtual ~Monster() = 0;
    //virtual string GetName() const = 0;
    const string GetName(); // 모두 Name 이라는 값을 반환하는 같은 동작 하므로 순수 가상함수, 가상함수로 사용하지 않음
    virtual Item* DropItem() = 0; // Logic for item drop
    virtual void Hit(int damage) override;
    virtual void Attack() override;
    virtual void Die();
    virtual void TestPrint();

protected:
    int DungeonLevel;
    int PlayerLevel;

    int CurrentHealth; // TODO : 임시 변수. 깃 머지 후 Character.h에서 상속 받아 사용할 것이므로 지워야 함.

    virtual void Magnification();
};