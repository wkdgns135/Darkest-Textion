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
	name = "����� ����(Heart of Darkness)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���", 0, 0, 1.5f), MonsterAttackInfo("���", 0, 1, 10) }; //���ݷ� 150% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����", 3, 0, 1.5f), MonsterAttackInfo("����", 3, 3, 1.5f, 2) }; //���ݷ� 150% ��ŭ ��� ����, ���ݷ� 150% ��ŭ �ߵ� ����. �� 3, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("�������", 4, 0, 1.5f), MonsterAttackInfo("�������", 4, 1, 30) }; //���ݷ� 150% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 30 ����. �� 4, ���� 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("�� �����ֿ��� ����", 10, 0, player->GetHealth()) }; //���(������ �ϰ�). �� 10 ���� 0

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
	name = "��Ȥ�� ���̷�(Alluring Siren)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("�����Ű��", 0, 0, 1.0f), MonsterAttackInfo("�����Ű��", 0, 3, 1.0f, 2) }; //���ݷ� 100% ��ŭ ���� ����, ���ݷ� 100% ��ŭ ��� ����. �� 0, ���� 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����", 3, 0, 1.0f), MonsterAttackInfo("����", 3, 1, 10) }; //���ݷ� 100% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 3, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����", 4, 0, 2.0f), MonsterAttackInfo("����", 4, 2, 1.2f, 3) }; //���ݷ� 200% ��ŭ ��� ����, ���ݷ� 20% ����. �� 4, ���� 3
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("����� �뷡", 10, 4, 0, 5) }; //. Ȯ�������� �÷��̾ �����θ� �����ϰ� ��. �� 10 ���� 5
	
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
	name = "�ޱ׷� �����Ҹ�(Wizened Hag)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���� ������", 0, 0, 1.0f) }; //���ݷ� 100% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("������ ���", 3, 0, 0.7f), MonsterAttackInfo("������ ���", 3, 1, 10) }; //���ݷ� 70% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 3, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("��Ʃ ������", 5, 0, 0.5f), MonsterAttackInfo("��Ʃ ������", 5, 2, 0.1f, 0, 4), MonsterAttackInfo("��Ʃ ������", 5, 1, 10) }; //���ݷ� 50% ��ŭ ��� ����, ���� ü�� 10% ����, �÷��̾� ��Ʈ���� 10 ����. �� 5, ���� 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("�� �ȿ� ��!", 10, 3, player->GetHealth() / damage, 5) }; //. �� �� �÷��̾� �ִ� ü���� 8% ��ŭ ����. �� 10 ���� 5

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);
	attackInfo.push_back(skill3);

	skill0.clear();
	skill1.clear();
	skill2.clear();
	skill3.clear();
}
