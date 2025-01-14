#pragma once
#include "GameManager.h"
#include "Character/Monster/Monster.h"
#include "Character/Monster/MonsterAttackInfo.h"

class MonsterAttack
{
public:
	MonsterAttack(Player* character);
	~MonsterAttack();

	void AttackToPlayer(int skillNum);
	void SetMonsterType(Monster* value);

	inline bool GetReflectionTrigger() { return isReflection; }
	void SetAttackInfo(vector<vector<MonsterAttackInfo>> info);

private:
	Monster* monster;
	Player* player;

	vector<vector<MonsterAttackInfo>> attackInfoByMonster;
	vector<MonsterAttackInfo> skillInfo0;
	vector<MonsterAttackInfo> skillInfo1;
	vector<MonsterAttackInfo> skillInfo2;
	vector<MonsterAttackInfo> skillInfo3;

	float decreaseValue;
	bool isReflection;
	bool isDecreaseContinue;

	int originRealDamage;
	int originHitRate;
	int originAvoidRate;
	float originDamageRate;

	void NormalAttack();
	void FirstSkillAttack();
	void SecondSkillAttack();
	void FinalSkillAttack();

	void ActionBySkillType(MonsterAttackInfo& info, bool onOff = true);

	void DecreasePlayerHealth(float value, bool onOff); //type0
	void IncreasePlayerStress(float value, bool onOff); //type1
	void IncreaseMonsterStat(int type, float value, bool onOff); //type2
	void ContinueDecreasePlayerHealth(float value, bool onOff); //type3
	void ReflecctionPlayerAttack(bool onOff); //type4
};

