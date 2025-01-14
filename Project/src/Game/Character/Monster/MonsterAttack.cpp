#include <vector>
#include "Character/Monster/MonsterAttack.h"

MonsterAttack::MonsterAttack(Player* character)
{
	player = character;
}

MonsterAttack::~MonsterAttack()
{
	for (int i = 0; i < attackInfoByMonster.size(); i++)
	{
		attackInfoByMonster[i].clear();
	}

	player = nullptr;
	monster = nullptr;

	skillInfo0.clear();
	skillInfo1.clear();
	skillInfo2.clear();
	skillInfo3.clear();
}

void MonsterAttack::SetMonsterType(Monster* value)
{
	monster = value;
	monster->SetRealDamage(monster->GetDamage());
	originRealDamage = monster->GetRealDamage();
	originAvoidRate = monster->GetAvoidRate();
	originHitRate = monster->GetHitRate();
	originDamageRate = monster->GetDamageRate();
	isReflection = false;
	isDecreaseContinue = false;
}

void MonsterAttack::SetAttackInfo(vector<vector<MonsterAttackInfo>> info)
{
	attackInfoByMonster = info;

	for (int i = 0; i < attackInfoByMonster.size(); i++)
	{
		for (int j = 0; j < attackInfoByMonster[i].size(); j++)
		{
			if (i == 0)
			{
				skillInfo0.push_back(attackInfoByMonster[i][j]);
				skillInfo0[j].SetCoolDownZero();
				skillInfo0[j].SetSkillCounterZero();
			}
			else if (i == 1)
			{
				skillInfo1.push_back(attackInfoByMonster[i][j]);
				skillInfo1[j].SetCoolDownZero();
				skillInfo1[j].SetSkillCounterZero();
			}
			else if (i == 2)
			{
				skillInfo2.push_back(attackInfoByMonster[i][j]);
				skillInfo2[j].SetCoolDownZero();
				skillInfo2[j].SetSkillCounterZero();
			}
			else
			{
				skillInfo3.push_back(attackInfoByMonster[i][j]);
				skillInfo3[j].SetCoolDownZero();
				skillInfo3[j].SetSkillCounterZero();
			}
		}
	}
}

void MonsterAttack::AttackToPlayer(int skillNum)
{
	if (isDecreaseContinue)
	{
		cout << "It is Tick Damage ";
		DecreasePlayerHealth(decreaseValue, true);
	}

	for (int i = 0; i < skillInfo0.size(); i++)
	{
		if (skillInfo0[i].GetSkillCounter() > 0) skillInfo0[i].DecreaseSkillCounter();
		else ActionBySkillType(skillInfo0[i], false);
	}

	for (int i = 0; i < skillInfo1.size(); i++)
	{
		if (skillInfo1[i].GetSkillCounter() > 0) skillInfo1[i].DecreaseSkillCounter();
		else ActionBySkillType(skillInfo1[i], false);
	}

	for (int i = 0; i < skillInfo2.size(); i++)
	{
		if (skillInfo2[i].GetSkillCounter() > 0) skillInfo2[i].DecreaseSkillCounter();
		else ActionBySkillType(skillInfo2[i], false);
	}

	if (monster->GetMonsterType() >= 40)
	{
		for (int i = 0; i < skillInfo3.size(); i++)
		{
			if (skillInfo3[i].GetSkillCounter() > 0) skillInfo3[i].DecreaseSkillCounter();
			else ActionBySkillType(skillInfo3[i], false);
		}

		if (skillInfo3[0].GetCoolDown() > 0) skillInfo3[0].DecreaseCoolDown();
	}

	if (skillInfo0[0].GetCoolDown() > 0) skillInfo0[0].DecreaseCoolDown();
	if (skillInfo1[0].GetCoolDown() > 0) skillInfo1[0].DecreaseCoolDown();
	if (skillInfo2[0].GetCoolDown() > 0) skillInfo2[0].DecreaseCoolDown();
	
	switch (skillNum)
	{
	case 0:
		NormalAttack();
		break;

	case 1:
		FirstSkillAttack();
		break;

	case 2:
		SecondSkillAttack();
		break;

	case 3:
		FinalSkillAttack();
		break;
	}
}

void MonsterAttack::NormalAttack()
{
	if (skillInfo0[0].GetCoolDown() > 0)
	{
		cout << "Skill 0 is cooldown. Not Action." << endl;
		return;
	}
	cout << monster->GetName() << " Attack. Skill Name : " << skillInfo0[0].GetName() << endl;
	monster->SetCurrentSkillName(skillInfo0[0].GetName());
	for (int i = 0; i < skillInfo0.size(); i++)
	{
		skillInfo0[i].SetCoolDown(attackInfoByMonster[0][i].GetCoolDown());
		skillInfo0[i].SetSkillCounter(attackInfoByMonster[0][i].GetSkillCounter());
		ActionBySkillType(skillInfo0[i]);
	}
}

void MonsterAttack::FirstSkillAttack()
{
	if (skillInfo1[0].GetCoolDown() > 0)
	{
		NormalAttack();
		cout << "Skill 1 is cooldown. Change skill Num 0" << endl;
		return;
	}
	cout << monster->GetName() << " Attack. Skill Name : " << skillInfo1[0].GetName() << endl;
	monster->SetCurrentSkillName(skillInfo1[0].GetName());
	for (int i = 0; i < skillInfo1.size(); i++)
	{
		skillInfo1[i].SetCoolDown(attackInfoByMonster[1][i].GetCoolDown());
		skillInfo1[i].SetSkillCounter(attackInfoByMonster[1][i].GetSkillCounter());
		ActionBySkillType(skillInfo1[i]);
	}
}

void MonsterAttack::SecondSkillAttack()
{
	if (skillInfo2[0].GetCoolDown() > 0)
	{
		FirstSkillAttack();
		cout << "Skill 2 is cooldown. Change skill Num 1" << endl;
		return;
	}
	cout << monster->GetName() << " Attack. Skill Name : " << skillInfo2[0].GetName() << endl;
	monster->SetCurrentSkillName(skillInfo2[0].GetName());
	for (int i = 0; i < skillInfo2.size(); i++)
	{
		skillInfo2[i].SetCoolDown(attackInfoByMonster[2][i].GetCoolDown());
		skillInfo2[i].SetSkillCounter(attackInfoByMonster[2][i].GetSkillCounter());
		ActionBySkillType(skillInfo2[i]);
	}
}

void MonsterAttack::FinalSkillAttack()
{
	if (skillInfo3[0].GetCoolDown() > 0)
	{
		SecondSkillAttack();
		cout << "Skill 2 is cooldown. Change skill Num 1" << endl;
		return;
	}
	cout << monster->GetName() << " Attack. Skill Name : " << skillInfo3[0].GetName() << endl;
	monster->SetCurrentSkillName(skillInfo3[0].GetName());
	for (int i = 0; i < skillInfo3.size(); i++)
	{
		skillInfo3[i].SetCoolDown(attackInfoByMonster[3][i].GetCoolDown());
		skillInfo3[i].SetSkillCounter(attackInfoByMonster[3][i].GetSkillCounter());
		ActionBySkillType(skillInfo3[i]);
	}
}

void MonsterAttack::ActionBySkillType(MonsterAttackInfo& info, bool onOff) //fasle = off, true = on
{
	switch (info.GetSkillType())
	{
	case 0: //DecreasePlayerHealth(int value)
		DecreasePlayerHealth(info.GetSkillValue(), onOff);
		break;

	case 1: //IncreasePlayerStress(int value)
		IncreasePlayerStress(info.GetSkillValue(), onOff);
		break;

	case 2: //IncreaseMonsterStat(int type, int value)
		IncreaseMonsterStat(info.GetTargetType(), info.GetSkillValue(), onOff);
		break;

	case 3: //ContinueDecreasePlayerHealth(int turn, int value)
		ContinueDecreasePlayerHealth(info.GetSkillValue(), onOff);
		break;

	case 4: //ReflecctionPlayerAttack(bool onOff)
		ReflecctionPlayerAttack(onOff);
		break;
	}
}

void MonsterAttack::DecreasePlayerHealth(float value, bool onOff)
{
	if (onOff)
	{
		//player->Hit(monster->GetRealDamage() * value);
		cout << monster->GetName() << " Attack To Player. Attack Damage = " << originRealDamage * value << endl;
	}
}

void MonsterAttack::IncreasePlayerStress(float value, bool onOff)
{
	if (onOff)
	{
		//player->AddStress(value);
		cout << monster->GetName() << " Attack To Player. Attack is Increase Stress. Stress = " << value << endl;
	}
}

void MonsterAttack::IncreaseMonsterStat(int type, float value, bool onOff)
{
	switch (type)
	{
	case 0: //realDamage
		if (onOff)
		{
			monster->SetRealDamage(monster->GetRealDamage() * value);
			cout << monster->GetName() << " Increase RealDamaage. Post increase RealDamage = " << monster->GetRealDamage() << endl;
		}
		else
		{
			monster->SetRealDamage(originRealDamage);
		}
		break;

	case 1: //hitRate
		if (onOff)
		{
			monster->SetHitRate(originHitRate + value);
			cout << monster->GetName() << " Increase HitRate. Post increase HitRate = " << monster->GetHitRate() << endl;
		}
		else
		{
			monster->SetHitRate(originHitRate);
		}
		break;

	case 2: //avoidRate
		if (onOff)
		{
			monster->SetAvoidRate(originAvoidRate + value);
			cout << monster->GetName() << " Increase AvoidRate. Post increase AvoidRate = " << monster->GetAvoidRate() << endl;
		}
		else
		{
			monster->SetAvoidRate(originAvoidRate);
		}
		break;

	case 3: //damageRate
		if (onOff)
		{
			monster->SetDamageRate(value);
			cout << monster->GetName() << " Increase DamageRate. Post increase DamageRate = " << monster->GetDamageRate() << endl;
		}
		else
		{
			monster->SetDamageRate(originDamageRate);
		}
		break;

	case 4: //currentHealth
		if (onOff)
		{
			monster->SetCurrentHealth(monster->GetCurrentHealth() + monster->GetMaxHealth() * value);
			if (monster->GetCurrentHealth() > monster->GetMaxHealth()) monster->SetCurrentHealth(monster->GetMaxHealth());
			cout << monster->GetName() << " Increase CurrentHealth. Post increase CurrentHealth = " << monster->GetCurrentHealth() << endl;
		}
	}
}

void MonsterAttack::ContinueDecreasePlayerHealth(float value, bool onOff)
{
	if (onOff)
	{
		isDecreaseContinue = true;
		decreaseValue = value;
		cout << monster->GetName() << " Active DecreaseContinue Skill. Skill Damage = " << monster->GetRealDamage() * value << endl;
	}
	else
	{
		isDecreaseContinue = false;
		decreaseValue = 0;
	}
}

void MonsterAttack::ReflecctionPlayerAttack(bool onOff)
{
	if (onOff)
	{
		isReflection = true;
		cout << monster->GetName() << " Active Reflection Skill." << endl;
	}
	else
	{
		isReflection = false;
	}
}