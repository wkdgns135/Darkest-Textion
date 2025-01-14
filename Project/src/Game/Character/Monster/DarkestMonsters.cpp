#include "Character/Monster/DarkestMonsters.h"

DarkestMonsterHorror::DarkestMonsterHorror() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

DarkestMonsterHorror::~DarkestMonsterHorror()
{

}

void DarkestMonsterHorror::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 2;
	name = "뒤섞이는 공포(Shuffling Horror)";

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 30;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 10;
	avoidRate += rank * 10;
	maxItemCount += rank / 2;
}

void DarkestMonsterHorror::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("격렬한 맥동", 0, 0, 0.9f) }; //공격력 90%만큼 노멀 공격
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("분열의 메아리", 3, 0, 1.5f), MonsterAttackInfo("분열의 메아리", 3, 1, 15)}; //공격력 150% 만큼 노멀 공격, 플레이어 스트레스 15 증가. 쿨 3, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("찢기", 5, 0, 1.0f), MonsterAttackInfo("찢기", 5, 3, 1.0f, 3)}; //공격력 100% 만큼 노멀 공격, 공격력 100% 만큼 출혈 지속. 쿨 5, 지속 3

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

DarkestMonsterCyst::DarkestMonsterCyst() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

DarkestMonsterCyst::~DarkestMonsterCyst()
{

}

void DarkestMonsterCyst::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 2;
	name = "거대한 낭종(Mammoth Cyst)";

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 31;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
}

void DarkestMonsterCyst::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("돌출된 시선", 0, 0, 0.8f), MonsterAttackInfo("돌출된 시선", 0, 1, 5)}; //플레이어 스트레스 5 증가, 공격력 80% 만큼 노멀 공격. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("소화", 3, 3, 1.5f, 2) }; //공격력 150% 만큼 중독 공격. 쿨 3, 지속 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("재활성화", 5, 2, 0.2f, 0, 4), MonsterAttackInfo("재활성화", 5, 2, 1.25f, 3, 0)}; //체력 회복 20%, 대미지 강화 25%. 쿨 5, 지속 3

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

DarkestMonsterTemplar::DarkestMonsterTemplar() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

DarkestMonsterTemplar::~DarkestMonsterTemplar()
{

}

void DarkestMonsterTemplar::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 2;
	name = "기사단 장군(Templar Warlord)";

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 32;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
}

void DarkestMonsterTemplar::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("종말의 날", 0, 3, 0.8f, 2) }; //공격력 80% 만큼 중독 공격. 쿨 0, 지속 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("독침 발사", 3, 3, 0.8f, 2), MonsterAttackInfo("독침 발사", 3, 0, 1.2f)}; //공격력 80% 만큼 중독 공격, 공격력 120%만큼 노멀 공격. 쿨 3, 지속 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("종말의 계시", 5, 1, 40) }; //플레이어 스트레스 40 증가. 쿨 5, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

DarkestMonsterHound::DarkestMonsterHound() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

DarkestMonsterHound::~DarkestMonsterHound()
{

}

void DarkestMonsterHound::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 2;
	name = "살점 사냥개(Flesh Hound)";

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 0;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
}

void DarkestMonsterHound::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("뜯어먹기", 0, 0, 0.7f) }; //공격력 70% 만큼 노멀 공격. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("낚아채기", 2, 0, 1.0f) }; //공격력 100% 만큼 노멀 공격. 쿨 2, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("갉기", 3, 0, 1.2f), MonsterAttackInfo("갉기", 3, 1, 5)}; //공격력 120% 만큼 노멀 공격, 플레이어 스트레스 5 증가. 쿨 3, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

DarkestMonsterWitch::DarkestMonsterWitch() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

DarkestMonsterWitch::~DarkestMonsterWitch()
{

}

void DarkestMonsterWitch::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = 2;
	name = "승천한 마녀(Ascended Witch)";

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 0;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
}

void DarkestMonsterWitch::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("운명의 밀침", 0, 0, 0.5f), MonsterAttackInfo("운명의 밀침", 0, 1, 5) }; //공격력 50% 만큼 노멀 공격, 플레이어 스트레스 5 증가. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("운명의 당김", 3, 0, 0.5f), MonsterAttackInfo("운명의 당김", 3, 1, 10) }; //공격력 50% 만큼 노멀 공격, 플레이어 스트레스 10 증가. 쿨 3, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("운명의 폭로", 5, 0, 0.5f), MonsterAttackInfo("운명의 폭로", 5, 1, 15) }; //공격력 50% 만큼 노멀 공격, 플레이어 스트레스 15 증가. 쿨 5, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}
