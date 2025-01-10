#pragma once
#include "Character/Character.h"
#include "Item/Item.h"
#include <iostream>
#include <random>

class Monster abstract : public Character
{
public:
    //TODO : ���� ������ �� ���� ���̵� ���� �־�� ��. 0~3 /// �� ������ ĳ���� ������ ����ϹǷ� �÷��̾� ������ �޾ƾ� ��.
    Monster(int dungeonLevel, int playerLevel);
    virtual ~Monster() = 0;
    //virtual string GetName() const = 0;
    inline string GetName() const { return name; } // ��� Name �̶�� ���� ��ȯ�ϴ� ���� ���� �ϹǷ� ���� �����Լ�, �����Լ��� ������� ����
    virtual Item* DropItem() = 0; // Logic for item drop
    virtual void Hit(int damage) override;
    virtual void Attack() override;
    virtual void Die();
    virtual void TestPrint();

protected:
    int DungeonLevel;
    int PlayerLevel;

    virtual void Magnification();
};