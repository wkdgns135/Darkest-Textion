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
    //TODO : ���� ������ �� ���� ���̵� ���� �־�� ��. 0~3 /// �� ������ ĳ���� ������ ����ϹǷ� �÷��̾� ������ �޾ƾ� ��.
    Monster(int dLevel);
    virtual ~Monster() = 0;
    inline string GetName() const { return name; } // ��� Name �̶�� ���� ��ȯ�ϴ� ���� ���� �ϹǷ� ���� �����Լ�, �����Լ��� ������� ����
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