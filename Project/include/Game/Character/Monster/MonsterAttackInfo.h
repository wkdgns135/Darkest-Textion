#pragma once

class MonsterAttackInfo
{
public:
	MonsterAttackInfo(string skillName, int coolDownValue, int skillTypeValue, float value, int skillCounterValue = 0, int targetTypeValue = 0)
	{
		name = skillName;
		coolDown = coolDownValue;
		skillCounter = skillCounterValue;
		skillType = skillTypeValue;
		skillValue = value;
		targetType = targetTypeValue;
	}

	inline string GetName() const { return name; }
	inline int GetCoolDown() const { return coolDown; }
	inline int GetSkillCounter() const { return skillCounter; }
	inline int GetSkillType() const { return skillType; }
	inline int GetTargetType() const { return targetType; }
	inline float GetSkillValue() const { return skillValue; }
	inline void DecreaseSkillCounter() { --skillCounter; }
	inline void DecreaseCoolDown() { --coolDown; }
	inline void SetCoolDownZero() { coolDown = 0; }
	inline void SetSkillCounterZero() { skillCounter = 0; }
	inline void SetCoolDown(int value) { coolDown = value; }
	inline void SetSkillCounter(int value) { skillCounter = value; }

private:
	string name;
	int coolDown;
	int skillCounter;
	int skillType;
	float skillValue;
	int targetType; // 0 : realDamage, 1 : hitRate, 2 : avoidRate, 3 : damageRate, 4 : currentHealth
};