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
	name = "�ڼ��̴� ����(Shuffling Horror)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("�ݷ��� �Ƶ�", 0, 0, 0.9f) }; //���ݷ� 90%��ŭ ��� ����
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("�п��� �޾Ƹ�", 3, 0, 1.5f), MonsterAttackInfo("�п��� �޾Ƹ�", 3, 1, 15)}; //���ݷ� 150% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 15 ����. �� 3, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����", 5, 0, 1.0f), MonsterAttackInfo("����", 5, 3, 1.0f, 3)}; //���ݷ� 100% ��ŭ ��� ����, ���ݷ� 100% ��ŭ ���� ����. �� 5, ���� 3

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
	name = "�Ŵ��� ����(Mammoth Cyst)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("����� �ü�", 0, 0, 0.8f), MonsterAttackInfo("����� �ü�", 0, 1, 5)}; //�÷��̾� ��Ʈ���� 5 ����, ���ݷ� 80% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("��ȭ", 3, 3, 1.5f, 2) }; //���ݷ� 150% ��ŭ �ߵ� ����. �� 3, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("��Ȱ��ȭ", 5, 2, 0.2f, 0, 4), MonsterAttackInfo("��Ȱ��ȭ", 5, 2, 1.25f, 3, 0)}; //ü�� ȸ�� 20%, ����� ��ȭ 25%. �� 5, ���� 3

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
	name = "���� �屺(Templar Warlord)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("������ ��", 0, 3, 0.8f, 2) }; //���ݷ� 80% ��ŭ �ߵ� ����. �� 0, ���� 2
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("��ħ �߻�", 3, 3, 0.8f, 2), MonsterAttackInfo("��ħ �߻�", 3, 0, 1.2f)}; //���ݷ� 80% ��ŭ �ߵ� ����, ���ݷ� 120%��ŭ ��� ����. �� 3, ���� 2
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("������ ���", 5, 1, 40) }; //�÷��̾� ��Ʈ���� 40 ����. �� 5, ���� 0

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
	name = "���� ��ɰ�(Flesh Hound)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("���Ա�", 0, 0, 0.7f) }; //���ݷ� 70% ��ŭ ��� ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����ä��", 2, 0, 1.0f) }; //���ݷ� 100% ��ŭ ��� ����. �� 2, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����", 3, 0, 1.2f), MonsterAttackInfo("����", 3, 1, 5)}; //���ݷ� 120% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 5 ����. �� 3, ���� 0

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
	name = "��õ�� ����(Ascended Witch)";

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
	vector<MonsterAttackInfo> skill0 = { MonsterAttackInfo("����� ��ħ", 0, 0, 0.5f), MonsterAttackInfo("����� ��ħ", 0, 1, 5) }; //���ݷ� 50% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 5 ����. �� 0, ���� 0
	vector<MonsterAttackInfo> skill1 = { MonsterAttackInfo("����� ���", 3, 0, 0.5f), MonsterAttackInfo("����� ���", 3, 1, 10) }; //���ݷ� 50% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 10 ����. �� 3, ���� 0
	vector<MonsterAttackInfo> skill2 = { MonsterAttackInfo("����� ����", 5, 0, 0.5f), MonsterAttackInfo("����� ����", 5, 1, 15) }; //���ݷ� 50% ��ŭ ��� ����, �÷��̾� ��Ʈ���� 15 ����. �� 5, ���� 0

	attackInfo.push_back(skill0);
	attackInfo.push_back(skill1);
	attackInfo.push_back(skill2);

	skill0.clear();
	skill1.clear();
	skill2.clear();
}
