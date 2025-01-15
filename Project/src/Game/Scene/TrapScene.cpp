#include "Scene/TrapScene.h"
#include "Scene/DungeonScene.h"
#include "Utility.h"
#include "Scene/SceneManager.h"


void TrapScene::Enter()
{
	DungeonScene::Enter();

	gameManager = GameManager::GetInstance();
	player = gameManager.GetPlayer();

	SelectSearchOrMove();

	//RandomTrapEncounter();
}

void TrapScene::Update()
{
	DungeonScene::Update();
	
}

void TrapScene::Exit()
{
	DungeonScene::Exit();

}

void TrapScene::SelectSearchOrMove()
{
	Sprite* question = new Sprite("drawable/Trap/trapQuestion.bmp", { 100, 80 }, 300, 100);
	renderer->AddSprite(question);

	Sprite* answer1 = new Sprite("drawable/Trap/answer1.bmp", { 30, 250 }, 100, 30);
	renderer->AddSprite(answer1);

	Sprite* answer2 = new Sprite("drawable/Trap/answer2.bmp", { 350, 250 }, 100, 30);
	renderer->AddSprite(answer2);

	AddInputEvent(Key_1, [this]() {RandomTrapEncounter();});
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<DungeonScene>();});
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<SelectDungeonScene>(); });

}

bool TrapScene::IsActiveTrap(EDungeon dungeonRank)
{
	bool isActive = false;
	int activeValue = 0;
	int minValue = 0;
	int maxValue = 100;
	
	switch (dungeonRank)
	{
	case EDungeon::Weald: activeValue = 50; break;
	case EDungeon::Cove: activeValue = 30; break;
	case EDungeon::DarkestDungeon: activeValue = 10; break;
	}

	if (activeValue <= GetRandomValue(minValue, maxValue)) isActive = true;

	return isActive;
}

void TrapScene::RandomTrapEncounter()
{
	renderer->ClearSprite();

	EDungeon dungeonRank = gameManager.GetCurrentDungeon();

	if (IsActiveTrap(dungeonRank))
	{
		ETrap trap = (ETrap)GetRandomValue(0, kindOfTrap - 1);
		int trapValue = 0;

		switch (trap)
		{
		case ETrap::Stress: 
			trapValue = 10 * ((int)dungeonRank + 1); 
			PrintOnTrap(trap, trapValue);
			player->AddStress(trapValue);
			break;

		case ETrap::Hit: 
			trapValue = player->GetHealth() * 2 / 100 * ((int)dungeonRank + 1); 
			PrintOnTrap(trap, trapValue);
			player->AddHealth(-trapValue);
			break;
		}
	}
	else PrintAvoidTrap();

	Sprite* moveNext = new Sprite("drawable/Trap/moveNext.bmp", { 30, 250 }, 170, 30);
	renderer->AddSprite(moveNext);

	//Sleep(2000);
	//SceneManager::GetInstance().ChangeScene<DungeonScene>();
	
	//AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<DungeonScene>();});
}

void TrapScene::PrintOnTrap(ETrap trap, int trapValue)
{
	Sprite* onTrapIcon = new Sprite("drawable/Trap/onTrap.bmp", { 70, 100 }, 100, 100);
	renderer->AddSprite(onTrapIcon);

	Sprite* onHpTrap = new Sprite("drawable/Trap/decreaseHp.bmp", { 170, 130 }, 100, 30);
	Sprite* onStressTrap = new Sprite("drawable/Trap/increaseStress.bmp", { 170, 130 }, 100, 30);

	switch (trap)
	{
	case ETrap::Stress:
		
		renderer->AddSprite(onStressTrap);
		break;

	case ETrap::Hit:
		
		renderer->AddSprite(onHpTrap);
		break;
	}

	renderer->DrawNumber(trapValue, { 270, 110 }, 60, 80);
}

void TrapScene::PrintAvoidTrap()
{
	Sprite* lucky = new Sprite("drawable/Trap/lucky.bmp", { 70, 120 }, 50, 50);
	renderer->AddSprite(lucky);
	
	Sprite* avoidTrap = new Sprite("drawable/Trap/avoidTrap.bmp", { 120, 120 }, 300, 50);
	renderer->AddSprite(avoidTrap);
}
