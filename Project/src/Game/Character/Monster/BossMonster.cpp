#include "Character/Monster/BossMonster.h"

BossMonsterHeart::BossMonsterHeart() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);
}

BossMonsterHeart::~BossMonsterHeart()
{
	
}

void BossMonsterHeart::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 5;
	monsterType = 42;
	name = "어둠의 심장(Heart of Darkness)";

	Magnification();
	SetAttackInfo();

	health *= 2.0f;
	damage *= 2.0f;
	currentHealth = health;

	hitRate = 113;
	avoidRate = 23;
	criticalRate = 12;
	speed = 10;

	minDropValue = 50;
	artifactRate = 30;
	maxItemRank = 100;
	maxItemCount = 4;
}

void BossMonsterHeart::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("찌르기", 0, 0, 1.5f), MonsterAttackInfo("찌르기", 0, 1, 10) }; //공격력 150% 만큼 노멀 공격, 플레이어 스트레스 10 증가. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("용해", 3, 0, 1.5f), MonsterAttackInfo("용해", 3, 3, 1.5f, 2) }; //공격력 150% 만큼 노멀 공격, 공격력 150% 만큼 중독 공격. 쿨 3, 지속 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("알지어다", 4, 0, 1.5f), MonsterAttackInfo("알지어다", 4, 1, 30) }; //공격력 150% 만큼 노멀 공격, 플레이어 스트레스 30 증가. 쿨 4, 지속 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("네 조물주에게 오라", 10, 0, player->GetHealth()) }; //즉사(죽음의 일격). 쿨 10 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);
	attackInfo.push_back(skill3);

	skill0.clear();
	skill1.clear();
	skill2.clear();
	skill3.clear();
}

BossMonsterSiren::BossMonsterSiren() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);
}

BossMonsterSiren::~BossMonsterSiren()
{

}

void BossMonsterSiren::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 4;
	monsterType = 41;
	name = "유혹의 세이렌(Alluring Siren)";

	Magnification();
	SetAttackInfo();

	health *= 1.6f;
	damage *= 1.6f;
	currentHealth = health;

	hitRate = 90;
	avoidRate = 21;
	criticalRate = 6;
	speed = 6;

	minDropValue = 40;
	artifactRate = 25;
	maxItemRank = 95;
	maxItemCount = 3;
}

void BossMonsterSiren::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("집어삼키기", 0, 0, 1.0f), MonsterAttackInfo("집어삼키기", 0, 3, 1.0f, 2) }; //공격력 100% 만큼 출혈 공격, 공격력 100% 만큼 노멀 공격. 쿨 0, 지속 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("수압", 3, 0, 1.0f), MonsterAttackInfo("수압", 3, 1, 10) }; //공격력 100% 만큼 노멀 공격, 플레이어 스트레스 10 증가. 쿨 3, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("만조", 4, 0, 2.0f), MonsterAttackInfo("만조", 4, 2, 1.2f, 3) }; //공격력 200% 만큼 노멀 공격, 공격력 20% 증가. 쿨 4, 지속 3
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("욕망의 노래", 10, 4, 0, 5) }; //. 확률적으로 플레이어가 스스로를 공격하게 함. 쿨 10 지속 5
	
	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);
	attackInfo.push_back(skill3);

	skill0.clear();
	skill1.clear();
	skill2.clear();
	skill3.clear();
}

BossMonsterHag::BossMonsterHag() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);
}

BossMonsterHag::~BossMonsterHag()
{

}

void BossMonsterHag::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 3;
	monsterType = 40;
	name = "쭈그렁 마귀할멈(Wizened Hag)";

	Magnification();
	SetAttackInfo();

	health *= 1.2f;
	damage *= 1.2f;
	currentHealth = health;

	hitRate = 95;
	avoidRate = 5;
	criticalRate = 6;
	speed = 5;

	minDropValue = 30;
	artifactRate = 20;
	maxItemRank = 90;
	maxItemCount = 3;
}

void BossMonsterHag::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("육질 다지기", 0, 0, 1.0f) }; //공격력 100% 만큼 노멀 공격. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("마무리 양념", 3, 0, 0.7f), MonsterAttackInfo("마무리 양념", 3, 1, 10) }; //공격력 70% 만큼 노멀 공격, 플레이어 스트레스 10 증가. 쿨 3, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("스튜 맛보기", 5, 0, 0.5f), MonsterAttackInfo("스튜 맛보기", 5, 2, 0.1f, 0, 4), MonsterAttackInfo("스튜 맛보기", 5, 1, 10) }; //공격력 50% 만큼 노멀 공격, 현재 체력 10% 증가, 플레이어 스트레스 10 증가. 쿨 5, 지속 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("솥 안에 들어가!", 10, 3, player->GetHealth() / damage, 5) }; //. 매 턴 플레이어 최대 체력의 8% 만큼 공격. 쿨 10 지속 5

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);
	attackInfo.push_back(skill3);

	skill0.clear();
	skill1.clear();
	skill2.clear();
	skill3.clear();
}
