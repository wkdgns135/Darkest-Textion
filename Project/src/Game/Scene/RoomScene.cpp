#include "Scene/RoomScene.h"
#include "GameManager.h"
#include "Scene/SceneManager.h"
#include "Utility.h"

void RoomScene::NextRoom()
{
	int proba = GetRandomValue(0, 100);
	switch (GameManager::GetInstance().GetCurrentDungeon())
	{
		case Weald: break;
		case Cove: proba * 0.8; break;
		case DarkestDungeon: proba * 0.6; break;
	}
	if (proba < 10) {
		//TODO: ITEM ¹æ
		//SceneManager::GetInstance().ChangeScene<>()
	}
	else if (proba < 30) {
		//TODO: ±â¹Í ¹æ
		
	}
	else {
		SceneManager::GetInstance().ChangeScene<BattleScene>();
	}
}

void RoomScene::Enter()
{
	DungeonScene::Enter();

	Sprite* retreat = new Sprite("drawable/Ui/Retreat.bmp", { 0, 120 }, 100, 50);
	Sprite* nextRoom = new Sprite("drawable/Ui/NextRoom.bmp", { 400, 120 }, 100, 50);

	renderer->AddSprite(retreat);
	renderer->AddSprite(nextRoom);

	AddInputEvent(Key_1, [this]() {NextRoom(); });
}

void RoomScene::Update()
{
}

void RoomScene::Exit()
{
}
