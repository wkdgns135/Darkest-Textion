#include "Character/Monster/ForestMonsters.h"

ForestMonsterFungal::ForestMonsterFungal() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

ForestMonsterFungal::~ForestMonsterFungal()
{

}

void ForestMonsterFungal::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 10;

	switch (rank)
	{
	case 0:
		name = "긁어대는 곰팡이(Fungal Scratcher)";
		break;

	case 1:
		name = "쥐어뜯는 곰팡이(Fungal Grabber)";
		break;

	case 2:
		name = "할퀴는 곰팡이(Fungal Crawler)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;

	hitRate = 70 + rank * 10;
	avoidRate = rank * 10;
	criticalRate = 6 + rank * 3;
	speed = rank * 1;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void ForestMonsterFungal::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = {MonsterAttackInfo("더듬는 후려치기", 0, 0, 0.7f)}; //공격력 0.7% 만큼 노멀 공격. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = {MonsterAttackInfo("표식을 쫒아라", 2, 0, 1.5f)}; //공격력 1.5% 만큼 노멀 공격. 쿨 2, 지속 0
	vector<MonsterAttackInfo> skill2 = {MonsterAttackInfo("버둥거림", 3, 3, 1.2f, 2)}; //공격력 1.2% 만큼 중독 공격. 쿨 3, 지속 2

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

ForestMonsterGiant::ForestMonsterGiant() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);
}

ForestMonsterGiant::~ForestMonsterGiant()
{

}

void ForestMonsterGiant::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 11;

	switch (rank)
	{
	case 0:
		name = "더러운 거인(Unclean Giant)";
		break;

	case 1:
		name = "감염된 거인(Blighted Giant)";
		break;

	case 2:
		name = "타락한 거인(Corrupted Giant)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	
	hitRate = 80 + rank * 10;
	avoidRate = rank * 10;
	criticalRate = 6 + rank * 6;
	speed = rank * 1;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void ForestMonsterGiant::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("독성 포자", 0, 3, 0.7f, 2) }; //공격력 0.7% 만큼 중독 공격. 쿨 0, 지속 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("혼란 포자", 2, 0, 0.7f), MonsterAttackInfo("혼란 포자", 2, 2, 10, 2, 2)}; //회피율 10% 증가. 공격력 0.7% 만큼 노멀 공격. 쿨 2, 지속 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("나무둥치 후려치기", 5, 0, 2) }; //공격력 2.0% 만큼 노멀 공격. 쿨 5, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

ForestMonsterCrone::ForestMonsterCrone() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);
}

ForestMonsterCrone::~ForestMonsterCrone()
{
	
}

void ForestMonsterCrone::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 12;

	switch (rank)
	{
	case 0:
		name = "노파(Crone)";
		break;

	case 1:
		name = "끈질긴 노파(Tenaclous Crone)";
		break;

	case 2:
		name = "감염된 노파(Blighted Crone)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;

	hitRate = 80 + rank * 10;
	avoidRate = 10 + rank * 15;
	criticalRate = 6 + rank * 1;
	speed = rank + 8;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void ForestMonsterCrone::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("쇠약의 저주", 0, 0, 0.5f), MonsterAttackInfo("쇠약의 저주", 0, 2, 20, 2, 2)}; //회피율 20% 증가. 공격력 0.5% 만큼 노멀 공격. 쿨 0 지속 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("어둠을 받아들여라", 3, 1, 10) }; //플레이어 스트레스 10 증가. 쿨 3 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("악취 향로", 4, 1, 10), MonsterAttackInfo("악취 향로", 4, 3, 0.7f, 2)}; //플레이어 스트레스 10 증가. 공격력 0.7% 만큼 중독 공격. 쿨 4 지속 2 

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}
