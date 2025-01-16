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
#include "Scene/SceneManager.h"


void TreasureScene::OpenBox()
{
	// 아이템을 랜덤으로 생성
	int rnd = GetRandomValue(0, (int)EEnd-1);
	Sprite* itemImage;
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
		item = new KnightsCrest();
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
		itemImage = nullptr;
		num = 0;
		cout << "잘못된 값입니다" << endl;
		break;
	}
	renderer->ClearSprite();
	Sprite* panel = new Sprite("drawable/Treasure/Panel.bmp", { 170,110 }, 150, 50);
	itemImage = new Sprite(item->GetImagePath(), {170,80}, 150, 150);
	renderer->AddSprite(panel);
	renderer->AddFixSprite(itemImage);
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
		//Todo : 인벤토리보여주며 버릴 아이템 선택하게 하기
	}
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void TreasureScene::InitInputEvent()
{
	AddInputEvent(Key_1, [this]() {SelectItem(); });
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<DungeonInfoScene>(); });
}

void TreasureScene::SelectGetOrGiveUp()
{
	renderer->ClearSprite();

	Sprite* question = new Sprite("drawable/Treasure/TreasuerQuestion.bmp", { 100, 60 }, 300, 50);
	renderer->AddSprite(question);

	Sprite* answer1 = new Sprite("drawable/Treasure/answer1.bmp", { 30, 250 }, 100, 20);
	renderer->AddSprite(answer1);

	Sprite* answer2 = new Sprite("drawable/Treasure/answer2.bmp", { 350, 250 }, 100, 20);
	renderer->AddSprite(answer2);

	InitInputEvent();
}

void TreasureScene::Enter()
{
	DungeonScene::Enter();
	gameManager = GameManager::GetInstance();
	player = gameManager.GetPlayer();
	player = new Player("dddd");
	OpenBox();
	SelectGetOrGiveUp();
}
void TreasureScene::Update()
{
	DungeonScene::Update();
}
void TreasureScene::Exit()
{
	DungeonScene::Exit();
}