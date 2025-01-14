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
	name = "����� ����(Heart of Darkness)";

	Magnification();
	SetAttackInfo();

	health *= 2.0f;
	damage *= 2.0f;
	currentHealth = health;
	monsterType = 42;
	minDropValue += rank * 10;
	artifactRate += rank * 6;
	maxItemRank += rank * 15;
	hitRate += rank * 6;
	avoidRate += rank * 4;
	maxItemCount += rank / 2;
}

void BossMonsterHeart::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���", 0, 0, 1.5f), MonsterAttackInfo("���", 0, 1, 10) }; //���ݷ� 150% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����", 3, 0, 1.5f), MonsterAttackInfo("����", 3, 3, 1.5f, 2) }; //���ݷ� 150% ��ŭ ��� ����, ���ݷ� 150% ��ŭ �ߵ� ����. �� 3, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("�������", 4, 0, 1.5f), MonsterAttackInfo("�������", 4, 1, 30) }; //���ݷ� 150% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 30 ����. �� 4, ���� 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("�� �����ֿ��� ����", 10, 0, 10000) }; //���(������ �ϰ�). �� 10 ���� 0
	//player->GetHealth()�� ���� �ʿ� (skill3)
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
	name = "��Ȥ�� ���̷�(Alluring Siren)";

	Magnification();
	SetAttackInfo();

	health *= 1.6f;
	damage *= 1.6f;
	currentHealth = health;
	monsterType = 41;
	minDropValue += rank * 10;
	artifactRate += rank * 5;
	maxItemRank += rank * 14;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
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
	name = "�ޱ׷� �����Ҹ�(Wizened Hag)";

	Magnification();
	SetAttackInfo();

	health *= 1.2f;
	damage *= 1.2f;
	currentHealth = health;
	monsterType = 40;
	minDropValue += rank * 10;
	artifactRate += rank * 4;
	maxItemRank += rank * 13;
	hitRate += rank * 5;
	avoidRate += rank * 5;
	maxItemCount += rank / 2;
}

void BossMonsterHag::SetAttackInfo()
{
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���� ������", 0, 0, 1.0f) }; //���ݷ� 100% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("������ ���", 3, 0, 0.7f), MonsterAttackInfo("������ ���", 3, 1, 10) }; //���ݷ� 70% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 3, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("��Ʃ ������", 5, 0, 0.5f), MonsterAttackInfo("��Ʃ ������", 5, 2, 0.1f, 0, 4), MonsterAttackInfo("��Ʃ ������", 5, 1, 10) }; //���ݷ� 50% ��ŭ ��� ����, ���� ü�� 10% ����, �÷��̾� ��Ʈ���� 10 ����. �� 5, ���� 0
	vector<MonsterAttackInfo> skill3 = { MonsterAttackInfo("�� �ȿ� ��!", 10, 3, health * 0.08f / realDamage, 5) }; //. �� �� �÷��̾� �ִ� ü���� 8% ��ŭ ����. �� 10 ���� 5
	//player->GetHealth()�� ���� �ʿ� (skill 3)
	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);
	attackInfo.push_back(skill3);

	skill0.clear();
	skill1.clear();
	skill2.clear();
	skill3.clear();
}
