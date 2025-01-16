#include "GameManager.h"
#include "Scene/BattleScene.h"
#include "Character/Monster/MonsterSpawnHandle.h"
#include "Scene/SceneManager.h"

void BattleScene::ImportMonsterSprite()
{
	monsterAttack = new Sprite({ 100, 50 }, 200, 200);

	vector<string> sheetPath;
	for (char i = '0'; i < '6'; i++) {
		string path = "drawable/SpriteSheet/MonsterAttack_";
		path += i;
		path += ".bmp";
		sheetPath.push_back(path);
	}
	monsterAttack->AddAnimation(sheetPath, 0.05f);

	string monsterPath = "drawable/Monster/" + monster->GetName() + ".bmp";
	Sprite* monsterSprite = new Sprite(monsterPath, {150, 0}, 200, 200);
	renderer->AddFixSprite(monsterSprite);
}

void BattleScene::ImportPlayerSprite()
{
	playerAttack = new Sprite({ 150, 25 }, 150, 150);

	vector<string> sheetPath;
	for (char i = '0'; i < '6'; i++) {
		string path = "drawable/SpriteSheet/Attack_";
		path += i;
		path += ".bmp";
		sheetPath.push_back(path);
	}
	playerAttack->AddAnimation(sheetPath, 0.05f);
}

void BattleScene::ImportUiSprite()
{
	// 동적인 스프라이트 생성
	playerSkill = new Sprite("drawable/Ui/PlayerSkill.bmp", { 10, 240 }, 325, 60);
	monsterTurn = new Sprite("drawable/Ui/MonsterTurn.bmp", { 0, 0 }, 100, 50);
	playerTurn = new Sprite("drawable/Ui/PlayerTurn.bmp", { 0, 0 }, 100, 50);

	// 정적인 스프라이트 생성
	Sprite* Hp = new Sprite("drawable/Ui/HP.bmp", { 0, 200 }, 50, 50);
	Sprite* Dmg = new Sprite("drawable/Ui/Dmg.bmp", { 100, 200 }, 50, 50);
	Sprite* Str = new Sprite("drawable/Ui/STR.bmp", { 200, 200 }, 50, 50);
	Sprite* monsterHp = new Sprite("drawable/Ui/MonsterHpText.bmp", { 320, 0 }, 100, 50);


	renderer->AddFixSprite(Hp);
	renderer->AddFixSprite(Dmg);
	renderer->AddFixSprite(Str);
	renderer->AddFixSprite(monsterHp);
}

void BattleScene::MonsterTurn()
{	
	renderer->ClearSprite();
	renderer->AddSprite(monsterAttack);
	renderer->AddSprite(monsterTurn);
	UpdateNumber();

	monsterAttack->animation->PlayOnce([this]() {MonsterAttackFinish(); });
}

void BattleScene::PlayerTurn()
{
	EnableInputEvent();
	renderer->ClearSprite();
	renderer->AddSprite(playerSkill);
	renderer->AddSprite(playerTurn);
	UpdateNumber();
}

void BattleScene::EnableInputEvent()
{
	AddInputEvent(Key_Q, [this]() {this->PlayerAttack(1); });
	AddInputEvent(Key_W, [this]() {this->PlayerAttack(2); });
	AddInputEvent(Key_E, [this]() {this->PlayerAttack(3); });
	AddInputEvent(Key_R, [this]() {this->PlayerAttack(4); });
	AddInputEvent(Key_I, [this]() {UseInventory(); });
}

void BattleScene::PlayerAttack(int skillIndex)
{
	ClearEvent();
	player->SetMonster(monster);
	renderer->AddSprite(playerAttack);
	playerAttack->animation->PlayOnce([this, skillIndex]() {PlayerAttackFinish(skillIndex); });
}

void BattleScene::PlayerAttackFinish(int skillIndex)
{
	switch (skillIndex)
	{
		case 1: player->Skill1(); break;
		case 2: player->Skill2(); break;
		case 3: player->Skill3(); break;
		case 4: player->Skill4(); break;
		default:break;
	}

	if (monster->GetCurrentHealth() <= 0) {
		monster->Die();
		SceneManager::GetInstance().ChangeScene<RoomScene>();
	}else this->MonsterTurn();
}

void BattleScene::MonsterAttackFinish()
{
	monster->Attack();
	if (player->GetCurrentHealth() <= 0) {
		//TODO: 나중에 게임 오버 씬 추가해서 넘어가도록
		SceneManager::GetInstance().ChangeScene<TitleScene>();
	}
	else {
		if (player->GetStress() >= 100) {
			//TODO: 스트레스 100 이상시 붕괴 효과
		}
		else if (player->GetStress() >= 200) {
			//TODO: 나중에 게임 오버 씬 추가해서 넘어가도록
			SceneManager::GetInstance().ChangeScene<TitleScene>();
		}
		else {
			this->PlayerTurn();
		}
	}
}

void BattleScene::UseInventory()
{
	ClearEvent();
	renderer->ClearSprite();

	ShowInventory();

	cursor = 0;
	ShowCursor();

	AddInputEvent(EKeyEvent::Key_1, [this]() { this->MoveCursor(-1); });
	AddInputEvent(EKeyEvent::Key_2, [this]() { this->MoveCursor(1); });
	AddInputEvent(EKeyEvent::Key_3, [this]() { 
		auto inventory = player->GetItem();
		auto it = inventory.begin(); //리스트 첫번째 칸
		advance(it, cursor); //index만큼 뒤로 이동
		player->UseItem(it->first);
		});
	AddInputEvent(EKeyEvent::Key_I, [this]() { PlayerTurn(); });
}

void BattleScene::UpdateNumber()
{
	renderer->DrawNumber(player->GetCurrentHealth(), { 50, 200 }, 25, 50);
	renderer->DrawNumber(player->GetDamage(), { 150, 200 }, 25, 50);
	renderer->DrawNumber(player->GetStress(), { 250, 200 }, 25, 50);
	renderer->DrawNumber(monster->GetCurrentHealth(), { 410, 0 }, 50, 50);
}

void BattleScene::Enter()
{
	DungeonScene::Enter();
	GameManager gameManager = GameManager::GetInstance();
	
	player = gameManager.GetPlayer();
	MonsterSpawnHandle monsterSpawner;
	monster = monsterSpawner.GetSpawnMonsterByDungeonLevel(gameManager.GetCurrentDungeon());

	ImportUiSprite();
	ImportMonsterSprite();
	ImportPlayerSprite();

	if (player->GetSpeed() < monster->GetSpeed()) {
		battleState = EMonsterAttack;
		MonsterTurn();
	}
	else {
		battleState = EPlayerAttack;
		PlayerTurn();
	}
	
}

void BattleScene::Update()
{
	DungeonScene::Update();
}

void BattleScene::Exit()
{
	DungeonScene::Exit();
}
