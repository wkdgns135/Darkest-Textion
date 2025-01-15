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
		name = "����� �ּ���(Pelagic Shaman)";
		break;

	case 1:
		name = "����� ������(Pelagic Oracle)";
		break;

	case 2:
		name = "����� �����밡(Pelagic TideMaster)";
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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("�ĵ�ġ�� �й�", 0, 1, 5) }; //�÷��̾� ��Ʈ���� ���� 5. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("�ǽ��� Į��", 2, 0, 1) }; //���ݷ��� 100% ��ŭ ��� ����. �� 2, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("��ǳ", 3, 2, 0.1f, 0, 4) }; //�ִ� ü���� 10% ��ŭ ü�� ȸ��. �� 3, ���� 0

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
		name = "������ ���� ���ĸ�(Deep Stinger)";
		break;

	case 1:
		name = "������ ���� ���ĸ�(Energized Stinger)";
		break;

	case 2:
		name = "������ ���� ���ĸ�(Paralyzing Stinger)";
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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���� ���", 0, 0, 0.7f) }; //���ݷ� 70% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("������ �˼�", 3, 0, 1), MonsterAttackInfo("������ �˼�", 3, 2, 5, 2, 1)}; //���ݷ� 100% ��ŭ ��� ����, ���߷� 5 ���. �� 3, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����", 4, 0, 1.2f), MonsterAttackInfo("����", 4, 3, 0.5f, 2)}; //���ݷ� 120 ��ŭ ��� ����, ���ݷ� 50% ��ŭ ���� ������. �� 4, ���� 2

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
		name = "�ͻ��� �뿹(Drowned Thrall)";
		break;

	case 1:
		name = "����� �뿹(Pustulent Thrall)";
		break;

	case 2:
		name = "�Ҿ����� �뿹(Bloated Thrall)";
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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("��ǰ���� ����", 0, 1, 3) }; //�÷��̾��� ��Ʈ���� 3 ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����", 2, 1, 5) }; //�÷��̾��� ��Ʈ���� 5 ����. �� 2, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����", 3, 1, 7) }; //�÷��̾��� ��Ʈ���� 7 ����. �� 3, ���� 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}

