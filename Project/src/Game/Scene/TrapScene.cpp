#include "Scene/TrapScene.h"
#include "Scene/DungeonScene.h"
#include "Utility.h"
#include "Scene/SceneManager.h"


void TrapScene::Enter()
{
	DungeonScene::Enter();

	gameManager = GameManager::GetInstance();
	dropItem = new DropItemObj();
	player = gameManager.GetPlayer();
	currentFunc = ECurrentFunc::Enter;

	SelectSearchOrMove();
}

void TrapScene::Update()
{
	DungeonScene::Update();
	
}

void TrapScene::Exit()
{
	DungeonScene::Exit();

	delete dropItem;
	dropItem = nullptr;
}

void TrapScene::SelectSearchOrMove()
{
	renderer->ClearSprite();

	Sprite* question = new Sprite("drawable/Trap/trapQuestion.bmp", { 100, 60 }, 300, 50);
	renderer->AddSprite(question);

	Sprite* answer1 = new Sprite("drawable/Trap/answer1.bmp", { 30, 250 }, 100, 20);
	renderer->AddSprite(answer1);

	Sprite* answer2 = new Sprite("drawable/Trap/answer2.bmp", { 350, 250 }, 100, 20);
	renderer->AddSprite(answer2);

	AddInputEvent(Key_1, [this]() {SelectRandomTrapByLevel();});
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();}); //수정해야함.
}

bool TrapScene::IsActiveEvent(EDungeon dungeonRank)
{
	bool isActive = false;
	int activeValue = 0;
	int minValue = 0;
	int maxValue = 100;

	switch (dungeonRank)
	{
	case EDungeon::Weald: activeValue = 15; break;
	case EDungeon::Cove: activeValue = 10; break;
	case EDungeon::DarkestDungeon: activeValue = 5; break;
	}

	if (activeValue <= GetRandomValue(minValue, maxValue)) isActive = true;

	return isActive;
}

void TrapScene::SelectRandomTrapByLevel()
{
	renderer->ClearSprite();

	EDungeon dungeonRank = gameManager.GetCurrentDungeon();

	if (IsActiveEvent(dungeonRank))
	{
		Sprite* panel = new Sprite("drawable/Trap/Panel.bmp", { 150, 100 }, 200, 100); //다른 이미지 그냥 얹으면 구분 안 가서 밝은 패널 넣음
		renderer->AddSprite(panel);

		switch (dungeonRank)
		{
		case EDungeon::Weald: PrintDetectAntique(GetInfoByAntiqueOfWeald());
			break;

		case EDungeon::Cove: PrintDetectAntique(GetInfoByAntiqueOfCove());
			break;

		case EDungeon::DarkestDungeon: PrintDetectAntique(GetInfoByAntiqueOfDarkest());
			break;
		}
	}
	else PrintAvoidTrap(false);
}

void TrapScene::PrintDetectAntique(vector<string> value)
{
	string spritePath = "";
	string textPath = "";

	Vector2d SpritePos = { 150, 100 };
	int SpriteWidth = 200;
	int SpriteHeight = 100;

	Vector2d TextPos = { 100, 30 };
	int TextWidth = 300;
	int TextHeight = 20;

	spritePath = value[0];
	textPath = value[1];

	Sprite* onAntiqueSprite = new Sprite(spritePath, SpritePos, SpriteWidth, SpriteHeight);
	renderer->AddSprite(onAntiqueSprite);

	Sprite* onAntiqueText = new Sprite(textPath, TextPos, TextWidth, TextHeight); //'name' 을 발견했습니다. 
	renderer->AddSprite(onAntiqueText);

	Sprite* answer1 = new Sprite("drawable/Trap/answer1.bmp", { 30, 250 }, 100, 20); //확인한다
	renderer->AddSprite(answer1);

	Sprite* answer2 = new Sprite("drawable/Trap/answer2.bmp", { 350, 250 }, 100, 20); //지나친다
	renderer->AddSprite(answer2);

	ClearEvent();
	AddInputEvent(Key_1, [this]() {RandomTrapEncounter();});
	AddInputEvent(Key_2, []() {SceneManager::GetInstance().ChangeScene<RoomScene>();}); //수정해야함.
}

void TrapScene::RandomTrapEncounter()
{
	renderer->ClearSprite();
	ClearEvent();
	EDungeon dungeonRank = gameManager.GetCurrentDungeon();

	int isIncrease = GetRandomValue(0, 100);

	if (isIncrease < (10 + (int)dungeonRank * 10)) //10
	{
		//increase Animation
		Sprite* increaseAnim = new Sprite({ 110,10 }, 280, 280);
		vector<string> sheetPath1;

		for (char i = '0'; i <= '6'; i++) {
			string path = "drawable/Trap/OpenSheet/increaseOpen";
			path += i;
			path += ".bmp";
			sheetPath1.push_back(path);
		}

		increaseAnim->AddAnimation(sheetPath1, 0.2f);
		renderer->AddSprite(increaseAnim);
		increaseAnim->animation->PlayOnce([this]() {ActionIncreaseEvent((int)gameManager.GetCurrentDungeon()); });
	}
	else if (isIncrease < 80 + ((int)dungeonRank * 10)) //80
	{
		//decrease Animation
		Sprite* decreaseAnim = new Sprite({ 110,10 }, 280, 280);
		vector<string> sheetPath2;

		for (char i = '0'; i <= '3'; i++) {
			string path = "drawable/Trap/OpenSheet/decreaseOpen";
			path += i;
			path += ".bmp";
			sheetPath2.push_back(path);
		}

		decreaseAnim->AddAnimation(sheetPath2, 0.2f);
		renderer->AddSprite(decreaseAnim);
		decreaseAnim->animation->PlayOnce([this]() {ActionDecreaseEvent((int)gameManager.GetCurrentDungeon());; });
	}
	else
	{
		PrintAvoidTrap(true);
	}
}

void TrapScene::ActionIncreaseEvent(int dungeonLevel)
{
	int randomValue = GetRandomValue(0, 100);
	ETrap trap = ETrap::Health;

	if (randomValue < 30) trap = ETrap::Health; //30
	else if (randomValue < 60) trap = ETrap::Stress; //60
	else if (randomValue < 80) trap = ETrap::Gold; //80
	else if (randomValue < 90) trap = ETrap::Damage; //90
	else if (randomValue < 95) trap = ETrap::Speed; //95
	else
	{
		AddOrDeleteItemEvent(false);
		return;
	}

	string path = "drawable/Trap/";
	string notiPath = "drawable/Trap/";
	char sign = '+';
	int eventValue = 0;

	switch (trap)
	{
	case ETrap::Health:
		path += "increaseHp.bmp";
		notiPath += "Hp.bmp";
		sign = '+';
		eventValue = player->GetHealth() * (dungeonLevel + 1) * 0.05f;
		player->AddCurrentHealth(eventValue);
		break;

	case ETrap::Stress:
		path += "decreaseStress.bmp";
		notiPath += "Str.bmp";
		sign = '-';
		eventValue = 20;
		player->AddStress(-eventValue);
		break;

	case ETrap::Damage:
		path += "increaseDamage.bmp";
		notiPath += "Dmg.bmp";
		sign = '+';
		eventValue = player->GetDamage() * (dungeonLevel + 1) * 0.05f;
		player->AddDamage(eventValue);
		break;

	case ETrap::Speed:
		path += "increaseSpeed.bmp";
		notiPath += "Speed.bmp";
		sign = '+';
		eventValue = 1;
		player->AddSpeed(eventValue);
		break;

	case ETrap::Gold:
		path += "getGold.bmp";
		notiPath += "gold.bmp";
		sign = '+';
		eventValue = 500 + (100 * dungeonLevel * 2);
		player->AddGold(eventValue);
		break;
	}

	Sprite* notify = new Sprite(path, { 150, 60 }, 200, 20);
	renderer->AddSprite(notify);

	Sprite* stat = new Sprite(notiPath, { 180, 125 }, 60, 20);
	renderer->AddSprite(stat);

	string signPath = "drawable/Trap/";
	if (sign == '+') signPath += "plus.bmp";
	else signPath += "minors.bmp";
	Sprite* signValue = new Sprite(signPath, { 245, 126 }, 25, 20);
	renderer->AddSprite(signValue);

	renderer->DrawNumber(eventValue, { 265, 108 }, 50, 60);

	PrintMoveNext();
}

void TrapScene::ActionDecreaseEvent(int dungeonLevel)
{
	int randomValue = GetRandomValue(0, 100);
	ETrap trap = ETrap::Health;

	if (randomValue < 30) trap = ETrap::Health; //30
	else if (randomValue < 60) trap = ETrap::Stress; //60
	else if (randomValue < 80) trap = ETrap::Gold; //80
	else if (randomValue < 90) trap = ETrap::Damage; //90
	else if (randomValue < 95) trap = ETrap::Speed; //95
	else
	{
		AddOrDeleteItemEvent(true);
		return;
	}

	string path = "drawable/Trap/";
	string notiPath = "drawable/Trap/";
	char sign = '-';
	int eventValue = 0;

	switch (trap)
	{
	case ETrap::Health:
		path += "decreaseHp.bmp";
		notiPath += "Hp.bmp";
		sign = '-';
		eventValue = player->GetHealth() * (dungeonLevel + 1) * 0.05f;
		player->AddCurrentHealth(-eventValue);
		break;

	case ETrap::Stress:
		path += "increaseStress.bmp";
		notiPath += "Str.bmp";
		sign = '+';
		eventValue = 20;
		player->AddStress(eventValue);
		break;

	case ETrap::Damage:
		path += "decreaseDamage.bmp";
		notiPath += "Dmg.bmp";
		sign = '-';
		eventValue = player->GetDamage() * (dungeonLevel + 1) * 0.05f;
		player->AddDamage(-eventValue);
		break;

	case ETrap::Speed:
		if (player->GetSpeed() > 0)
		{
			path += "decreaseSpeed.bmp";
			notiPath += "Speed.bmp";
			sign = '-';
			eventValue = 1;
			player->AddSpeed(-eventValue);
		}
		else
		{
			path += "failDecreaseSpeed.bmp";
			notiPath += "Speed.bmp";
			sign = '-';
			eventValue = 0;
			player->AddSpeed(-eventValue);
		}
		break;

	case ETrap::Gold:
		if (player->GetGold() > 500 + (100 * dungeonLevel * -2))
		{
			path += "deleteGold.bmp";
			notiPath += "gold.bmp";
			sign = '-';
			eventValue = 500 + (100 * dungeonLevel * 2);
			player->AddGold(-eventValue);
		}
		else
		{
			path += "failDelete.bmp";
			notiPath += "gold.bmp";
			sign = '-';
			eventValue = player->GetGold();
			player->AddGold(-eventValue);
		}
		break;
	}

	Sprite* notify = new Sprite(path, { 150, 60 }, 200, 20);
	renderer->AddSprite(notify);

	Sprite* stat = new Sprite(notiPath, { 180, 125 }, 60, 20);
	renderer->AddSprite(stat);

	string signPath = "drawable/Trap/";
	if (sign == '+') signPath += "plus.bmp";
	else signPath += "minors.bmp";
	Sprite* signValue = new Sprite(signPath, { 245, 126 }, 25, 20);
	renderer->AddSprite(signValue);

	renderer->DrawNumber(eventValue, { 265, 108 }, 50, 60);

	PrintMoveNext();
}

void TrapScene::AddOrDeleteItemEvent(bool isDelete)
{
	int randomValue = GetRandomValue(0, 100);
	int consumableCount = 1;
	string path = "drawable/Trap/";
	Item* item = nullptr;

	if (isDelete)
	{
		if (player->GetItem().size() > 0)
		{
			if (randomValue <= 90)
			{
				path += "deleteConsumable.bmp";

				for (auto& it : player->GetItem())
				{
					if (it.second.GetItem()->GetName().find("Boost") != string::npos || it.second.GetItem()->GetName().find("Potion") != string::npos || it.second.GetItem()->GetName().find("Laudanum") != string::npos)
					{
						consumableCount = GetRandomValue(1, 3);
						it.second.AddCount(-consumableCount);
						if (it.second.GetCount() <= 0) player->GetItem().erase(it.first);
						break;
					}
				}
			}
			else
			{
				path += "deleteArtifact.bmp";

				for (auto& it : player->GetItem())
				{
					if (it.second.GetItem()->GetName().find("Stone") != string::npos || it.second.GetItem()->GetName().find("Crest") != string::npos || it.second.GetItem()->GetName().find("Snake") != string::npos)
					{
						it.second.AddCount(-1);
						if (it.second.GetCount() <= 0) player->GetItem().erase(it.first);
						break;
					}
				}
			}
		}
		else path += "failDelete.bmp"; //가진 게 없다.
	}
	else
	{
		if (randomValue <= 90)
		{
			path += "getConsumable.bmp";
			item = dropItem->GetConsumableItem(GetRandomValue(0, 100));
			consumableCount = GetRandomValue(1, 3);

			Sprite* itemSprite = new Sprite(item->GetImagePath(), { 200, 100 }, 100, 100);
			renderer->AddSprite(itemSprite);
		}
		else
		{
			path += "getArtifact.bmp";
			item = dropItem->GetArtifactItem(GetRandomValue(0, 100), GetRandomValue(0, 100));

			Sprite* itemSprite = new Sprite(item->GetImagePath(), { 200, 100 }, 100, 100);
			renderer->AddSprite(itemSprite);
		}

		if (player->GetItem().size() < 10)
		{
			player->AddItem(item, consumableCount);
		}
		else
		{
			if (player->GetItem().find(item->GetName()) != player->GetItem().end()) player->GetItem()[item->GetName()].AddCount(1);
			else
			{
				ClearEvent();

				ShowInventory();
				cursor = 0;
				ShowCursor();

				AddInputEvent(EKeyEvent::Key_1, [this]() { this->MoveCursor(-1); });
				AddInputEvent(EKeyEvent::Key_2, [this]() { this->MoveCursor(1); });
				AddInputEvent(EKeyEvent::Key_3, [this]() { DeleteItem(); });

				player->AddItem(item, consumableCount);
			}
		}
	}
	
	Sprite* notify = new Sprite(path, { 150, 60 }, 200, 20);
	renderer->AddSprite(notify);

	item = nullptr;

	PrintMoveNext();
}

void TrapScene::PrintAvoidTrap(bool isNotEvent)
{
	renderer->ClearSprite();

	if (isNotEvent)
	{
		Sprite* avoidTrap = new Sprite("drawable/Trap/notEvent.bmp", { 150, 120 }, 200, 20); //아무 일도 없었다.
		renderer->AddSprite(avoidTrap);
	}
	else
	{
		Sprite* avoidTrap = new Sprite("drawable/Trap/notFind.bmp", { 100, 120 }, 300, 20); //아무것도 발견하지 못 했다.
		renderer->AddSprite(avoidTrap);
	}

	PrintMoveNext();
}

void TrapScene::PrintMoveNext()
{
	Sprite* moveNext = new Sprite("drawable/Trap/moveNext.bmp", { 30, 250 }, 150, 20);
	renderer->AddSprite(moveNext);

	ClearEvent();
	AddInputEvent(Key_1, []() {SceneManager::GetInstance().ChangeScene<RoomScene>();}); // 수정해야함
}

void TrapScene::DeleteItem()
{
	auto it = player->GetItem().begin(); //리스트 첫번째 칸
	advance(it, cursor); //index만큼 뒤로 이동
	player->GetItem().erase(it->first);
}

vector<string> TrapScene::GetInfoByAntiqueOfWeald()
{
	EWealdAntique antique = (EWealdAntique)GetRandomValue(0, kindOfWeald - 1);

	string spritePath = "drawable/Trap/Weald/wealdAntique";
	spritePath += (int)antique + '0';
	spritePath += ".bmp";

	string textPath = "drawable/Trap/Weald/wealdAntiqueText";
	textPath += (int)antique + '0';
	textPath += ".bmp";

	return {spritePath, textPath};
}

vector<string> TrapScene::GetInfoByAntiqueOfCove()
{
	ECoveAntique antique = (ECoveAntique)GetRandomValue(0, kindOfCove - 1);

	string spritePath = "drawable/Trap/Cove/CoveAntique";
	spritePath += (int)antique + '0';
	spritePath += ".bmp";

	string textPath = "drawable/Trap/Cove/CoveAntiqueText";
	textPath += (int)antique + '0';
	textPath += ".bmp";

	return { spritePath, textPath };
}

vector<string> TrapScene::GetInfoByAntiqueOfDarkest()
{
	EDarkestAntique antique = (EDarkestAntique)GetRandomValue(0, kindOfDarkest - 1);

	string spritePath = "drawable/Trap/Darkest/darkestAntique";
	if ((int)antique < 10) spritePath += (int)antique + '0';
	else
	{
		spritePath += (int)antique / 10 + '0';
		spritePath += (int)antique % 10 + '0';
	}
	spritePath += ".bmp";

	string textPath = "drawable/Trap/Darkest/darkestAntiqueText";
	if ((int)antique < 10) textPath += (int)antique + '0';
	else
	{
		textPath += (int)antique / 10 + '0';
		textPath += (int)antique % 10 + '0';
	}
	textPath += ".bmp";

	return { spritePath, textPath };
}