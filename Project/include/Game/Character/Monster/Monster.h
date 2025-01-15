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
    inline void SetSpeed(int value) { speed = value; }
    inline void SetAvoidRate(int value) { avoidRate = value; }
    inline void SetHitRate(int value) { hitRate = value; }
    inline void SetDamageRate(float value) { damageRate = value; }
    inline void SetCriticalRate(int value) { criticalRate = value; }
    inline void SetCurrentHealth(int value) { currentHealth = value; }

    inline int GetMonsterType() { return monsterType; }
    inline int GetDamage() { return damage; }
    inline int GetRealDamage() { return realDamage; }
    inline int GetSpeed() { return speed; }
    inline int GetAvoidRate() { return avoidRate; }
    inline int GetHitRate() { return hitRate; }
    inline int GetCriticalRate() { return criticalRate; }
    inline int GetCurrentHealth() { return currentHealth; }
    inline int GetMaxHealth() { return health; }
    inline float GetDamageRate() { return damageRate; }
    
    inline void SetCurrentSkillName(string value) { skillName = value; }
    inline string GetCurrentSkillName() { return skillName; }

    inline void SetBoolSturn(bool value) { isSturn = value; }
    inline void SetStateSturnToMonster(int turn) { isSturn = true; turnOfSturn = turn; }
    inline void DecreaseTurnOfSturn() { --turnOfSturn; }

    inline bool GetBoolSturn() { return isSturn; }
    inline int GetTurnOfSturn() { return turnOfSturn; }

protected:
    int playerLevel;
    int rank;
    int monsterType;

    int speed;
    int realDamage;
    int avoidRate;
    int hitRate;
    int criticalRate;
    float damageRate;
    
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