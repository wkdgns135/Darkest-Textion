#include "Gamemanager.h"
#include "Scene/TreasureScene.h"
#include "Character/Player/Player.h"
#include "Global/ProjectEnum.h"
#include "Utility.h"
#include "Item/Artifact/ExpStone.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Consumable/DamageBoost.h"
#include "Item/Consumable/HealthPotion.h"


void TreasureScene::OpenBox()
{
	// �������� �������� ����
	int rnd = GetRandomValue(0, (int)EEnd-1);
	switch (rnd)
	{
	case (int)EExpStone:
		item = new ExpStone();
		num = 1;
		break;
	case (int)EHealthStone:
		item = new HealthStone();
		num = 1;
		break;
	case (int)EKnightsCrest:
		item = new KnightsCrest();;
		num = 1;
		break;
	case (int)ESnkeOil:
		item = new SnakeOil;
		num = 1;
		break;
	case (int)EDamageBoost:
		item = new DamageBoost();
		num = GetRandomValue(0, 5);
		break;
	case (int)EHealthPotion:
		item = new HealthPotion();
		num = GetRandomValue(0, 5);
		break;
	default:
		item = nullptr;
		num = 0;
		cout << "�߸��� ���Դϴ�" << endl;
		break;
	}

}
void TreasureScene::GetItem(int num)
{
	InitInputEvent();
}
void TreasureScene::SelectItem()
{
	ClearEvent();
	if (player->GetItem().size() < 10)
	{
		player->AddItem(item, num);
	}
	else
	{
		//Todo : �κ��丮�����ָ� ���� ������ �����ϰ� �ϱ�
	}
	
}
void TreasureScene::GiveUpItem()
{
	ClearEvent();
	//Todo : ������� ���ư���
}

void TreasureScene::InitInputEvent()
{
	AddInputEvent(Key_1, [this]() {SelectItem(); });
	AddInputEvent(Key_2, [this]() {GiveUpItem(); });
}

void TreasureScene::Enter()
{
	DungeonScene::Enter();
	GameManager gameManager = GameManager::GetInstance();
	player = gameManager.GetPlayer();
}
void TreasureScene::Update()
{
	DungeonScene::Update();
}
void TreasureScene::Exit()
{
	DungeonScene::Exit();
}