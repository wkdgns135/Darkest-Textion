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

	switch (rank)
	{
	case 0:
		name = "대양인 주술사(Pelagic Shaman)";
		break;

	case 1:
		name = "대양인 예언자(Pelagic Oracle)";
		break;

	case 2:
		name = "대양인 조류대가(Pelagic TideMaster)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 20;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 4;
	avoidRate += rank * 3;
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

	switch (rank)
	{
	case 0:
		name = "심해의 가시 해파리(Deep Stinger)";
		break;

	case 1:
		name = "충전된 가시 해파리(Energized Stinger)";
		break;

	case 2:
		name = "마비의 가시 해파리(Paralyzing Stinger)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 21;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 4;
	avoidRate += rank * 3;
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

	switch (rank)
	{
	case 0:
		name = "익사한 노예(Drowned Thrall)";
		break;

	case 1:
		name = "고름덩어리 노예(Pustulent Thrall)";
		break;

	case 2:
		name = "불어터진 노예(Bloated Thrall)";
		break;
	}

	Magnification();
	SetAttackInfo();

	currentHealth = health;
	monsterType = 22;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 10;
	hitRate += rank * 4;
	avoidRate += rank * 3;
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

