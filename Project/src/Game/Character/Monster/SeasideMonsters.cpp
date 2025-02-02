#include "Character/Monster/SeasideMonsters.h"

SeasideMonsterPelagic::SeasideMonsterPelagic() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

SeasideMonsterPelagic::~SeasideMonsterPelagic()
{

}

void SeasideMonsterPelagic::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 20;

	switch (rank)
	{
	case 0:
		name = "대양인 일족(Pelagic)";
		break;

	case 1:
		name = "대양인 수호자(Pelagic Guardian)";
		break;

	case 2:
		name = "대양인 주술사(Pelagic Shaman)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;

	hitRate = 80 + rank * 10;
	avoidRate = 7 + rank * 10;
	criticalRate = 5 + rank * 1;
	speed = 10 + rank * 1;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void SeasideMonsterPelagic::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("파도치는 압박", 0, 1, 5) }; //플레이어 스트레스 증가 5. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("의식의 칼질", 2, 0, 1) }; //공격력의 100% 만큼 노멀 공격. 쿨 2, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("순풍", 3, 2, 0.1f, 0, 4) }; //최대 체력의 10% 만큼 체력 회복. 쿨 3, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

SeasideMonsterStinger::SeasideMonsterStinger() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

SeasideMonsterStinger::~SeasideMonsterStinger()
{

}

void SeasideMonsterStinger::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 21;

	switch (rank)
	{
	case 0:
		name = "가시 해파리(Stinger)";
		break;

	case 1:
		name = "바다 구더기(Sea Maggot)";
		break;

	case 2:
		name = "거대 농게(Uca Major)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;

	hitRate = 90 + 8 * rank;
	avoidRate = 12 + rank * 10;
	criticalRate = 6 + rank * 5;
	speed = 7 + rank * 1;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void SeasideMonsterStinger::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("전기 충격", 0, 0, 0.7f) }; //공격력 70% 만큼 노멀 공격. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("따끔한 촉수", 3, 0, 1), MonsterAttackInfo("따끔한 촉수", 3, 2, 5, 2, 1)}; //공격력 100% 만큼 노멀 공격, 명중률 5 상승. 쿨 3, 지속 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("감전", 4, 0, 1.2f), MonsterAttackInfo("감전", 4, 3, 0.5f, 2)}; //공격력 120 만큼 노멀 공격, 공격력 50% 만큼 감전 데미지. 쿨 4, 지속 2

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

SeasideMonsterThrall::SeasideMonsterThrall() : Monster()
{
	InitializeByDungeonLevel();
	monsterActionHandle->GetMonsterAttack()->SetMonsterType(this);
	monsterActionHandle->GetMonsterAttack()->SetAttackInfo(attackInfo);
	monsterActionHandle->GetMonsterHit()->SetMonster(this);;
}

SeasideMonsterThrall::~SeasideMonsterThrall()
{

}

void SeasideMonsterThrall::InitializeByDungeonLevel()
{
	__super::InitializeByDungeonLevel();

	rank = GetRandomValue(0, 2);
	monsterType = 22;

	switch (rank)
	{
	case 0:
		name = "노예(Thrall)";
		break;

	case 1:
		name = "술에 절은 망자(Squiffy Ghast)";
		break;

	case 2:
		name = "익사한 선원(Drowned Crew)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;

	hitRate = 60 + rank * 10;
	avoidRate = 0 + rank * 10;
	criticalRate = 2 + rank * 2;
	speed = 0 + rank * 1;

	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 15;
	maxItemCount += rank / 2;
}

void SeasideMonsterThrall::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("거품물고 돌격", 0, 1, 3) }; //플레이어의 스트레스 3 증가. 쿨 0, 지속 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("복수", 2, 1, 5) }; //플레이어의 스트레스 5 증가. 쿨 2, 지속 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("집념", 3, 1, 7) }; //플레이어의 스트레스 7 증가. 쿨 3, 지속 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

