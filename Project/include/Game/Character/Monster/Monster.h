#pragma once

#include "GameManager.h"
#include "Character/Character.h"
#include "Item/Item.h"
#include "Character/Monster/DropItemObj.h"
//#include "Character/Monster/MonsterActionHandle.h" 
//#include "Character/Monster/MonsterAttackInfo.h"


class MonsterActionHandle;
class MonsterAttackInfo;
class Player;

class Monster abstract : public Character
{
public:
    Monster();
    virtual ~Monster() = 0;
    inline string GetName() const { return name; }
    virtual Item* DropItem();
    virtual void Hit(int damage) override;
    virtual void Attack() override;
    virtual void Die();
    virtual void TestPrint();

    inline void SetRealDamage(int value) { realDamage = value; }
    inline void SetAvoidRate(int value) { avoidRate = value; }
    inline void SetHitRate(int value) { hitRate = value; }
    inline void SetDamageRate(float value) { damageRate = value; }
    inline void SetCurrentHealth(int value) { currentHealth = value; }
    inline void SetCurrentSkillName(string value) { skillName = value; }
    inline void SetStateSturnToMonster(int turn) { isSturn = true; turnOfSturn = turn; }
    inline void SetBoolSturn(bool value) { isSturn = value; }
    inline void SetSpeed(float value) { speed = value; }
    inline void DecreaseTurnOfSturn() { --turnOfSturn; }
    inline int GetDamage() { return damage; }
    inline int GetRealDamage() { return realDamage; }
    inline int GetAvoidRate() { return avoidRate; }
    inline int GetHitRate() { return hitRate; }
    inline int GetTurnOfSturn() { return turnOfSturn; }
    inline int GetMonsterType() { return monsterType; }
    inline int GetCurrentHealth() { return currentHealth; }
    inline int GetMaxHealth() { return health; }
    inline bool GetBoolSturn() { return isSturn; }
    inline float GetDamageRate() { return damageRate; }
    inline float GetSpeed() { return speed; }
    inline string GetCurrentSkillName() { return skillName; }

protected:
    int playerLevel;
    int rank;
    int monsterType;
    int realDamage;

    int avoidRate;
    int hitRate;
    float damageRate;
    float speed;

    int minDropValue;
    int artifactRate;
    int maxItemRank;
    int maxItemCount;

    bool isSturn;
    int turnOfSturn;

    Player* player;
    DropItemObj* dropItemObj;
    MonsterActionHandle* monsterActionHandle;

    vector<vector<MonsterAttackInfo>> attackInfo;
    string skillName;

    virtual void SetAttackInfo() = 0;
    virtual void InitializeByDungeonLevel();
    void Magnification();
    int GetRandomValue(int min, int max);
};