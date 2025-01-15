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
		name = "�ܾ��� ������(Fungal Scratcher)";
		break;

	case 1:
		name = "����� ������(Fungal Grabber)";
		break;

	case 2:
		name = "������ ������(Fungal Crawler)";
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
	vector<MonsterAttackInfo> skill0 = {MonsterAttackInfo("����� �ķ�ġ��", 0, 0, 0.7f)}; //���ݷ� 0.7% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = {MonsterAttackInfo("ǥ���� �i�ƶ�", 2, 0, 1.5f)}; //���ݷ� 1.5% ��ŭ ��� ����. �� 2, ���� 0
	vector<MonsterAttackInfo> skill2 = {MonsterAttackInfo("���հŸ�", 3, 3, 1.2f, 2)}; //���ݷ� 1.2% ��ŭ �ߵ� ����. �� 3, ���� 2

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
		name = "������ ����(Unclean Giant)";
		break;

	case 1:
		name = "������ ����(Blighted Giant)";
		break;

	case 2:
		name = "Ÿ���� ����(Corrupted Giant)";
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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���� ����", 0, 3, 0.7f, 2) }; //���ݷ� 0.7% ��ŭ �ߵ� ����. �� 0, ���� 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("ȥ�� ����", 2, 0, 0.7f), MonsterAttackInfo("ȥ�� ����", 2, 2, 10, 2, 2)}; //ȸ���� 10% ����. ���ݷ� 0.7% ��ŭ ��� ����. �� 2, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("������ġ �ķ�ġ��", 5, 0, 2) }; //���ݷ� 2.0% ��ŭ ��� ����. �� 5, ���� 0

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
		name = "����(Crone)";
		break;

	case 1:
		name = "������ ����(Tenaclous Crone)";
		break;

	case 2:
		name = "������ ����(Blighted Crone)";
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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("����� ����", 0, 0, 0.5f), MonsterAttackInfo("����� ����", 0, 2, 20, 2, 2)}; //ȸ���� 20% ����. ���ݷ� 0.5% ��ŭ ��� ����. �� 0 ���� 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����� �޾Ƶ鿩��", 3, 1, 10) }; //�÷��̾� ��Ʈ���� 10 ����. �� 3 ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("���� ���", 4, 1, 10), MonsterAttackInfo("���� ���", 4, 3, 0.7f, 2)}; //�÷��̾� ��Ʈ���� 10 ����. ���ݷ� 0.7% ��ŭ �ߵ� ����. �� 4 ���� 2 

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}
