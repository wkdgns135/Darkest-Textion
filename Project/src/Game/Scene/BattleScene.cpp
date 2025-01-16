#include "GameManager.h"
#include "Scene/BattleScene.h"
#include "Character/Monster/MonsterSpawnHandle.h"
#include "Scene/SceneManager.h"

void BattleScene::ImportMonsterSprite()
{
	monsterAttackSprite = new Sprite({ 100, 50 }, 200, 200);

	vector<string> sheetPath;
	for (char i = '0'; i < '6'; i++) {
		string path = "drawable/SpriteSheet/MonsterAttack_";
		path += i;
		path += ".bmp";
		sheetPath.push_back(path);
	}
	monsterAttackSprite->AddAnimation(sheetPath, 0.05f);

	string monsterPath = "drawable/Monster/" + monster->GetName() + ".bmp";
	Sprite* monsterSprite = new Sprite(monsterPath, {150, 0}, 200, 200);
	renderer->AddFixSprite(monsterSprite);
}

void BattleScene::ImportPlayerSprite()
{
	playerSkill.resize(4);
	for (char i = '1'; i <= '4'; i++) {
		int index = i - '0' - 1;
		playerSkill[index] = new Sprite({150, 25}, 150, 150);
		vector<string> sheetPath;
		for (char j = '0'; j <= '5'; j++) {
			string path = "drawable/SpriteSheet/Skill_";
			path += i;
			path += "_";
			path += j;
			path += ".bmp";
			sheetPath.push_back(path);
		}
		playerSkill[index]->AddAnimation(sheetPath, 0.05f);
	}
}

void BattleScene::ImportUiSprite()
{
	// 동적인 스프라이트 생성
	playerSkillPanel = new Sprite("drawable/Ui/PlayerSkill.bmp", { 10, 240 }, 325, 60);
	monsterTurnSprite = new Sprite("drawable/Ui/MonsterTurn.bmp", { 0, 0 }, 100, 50);
	playerTurnSprite = new Sprite("drawable/Ui/PlayerTurn.bmp", { 0, 0 }, 100, 50);

	// 정적인 스프라이트 생성
	Sprite* Hp = new Sprite("drawable/Ui/HP.bmp", { 0, 200 }, 50, 50);
	Sprite* Str = new Sprite("drawable/Ui/STR.bmp", { 100, 200 }, 50, 50);
	Sprite* Dmg = new Sprite("drawable/Ui/Dmg.bmp", { 200, 200 }, 50, 50);
	Sprite* monsterHp = new Sprite("drawable/Ui/MonsterHpText.bmp", { 320, 0 }, 100, 50);
	Sprite* Floor = new Sprite("drawable/Ui/Floor.bmp", { 330, 250 }, 100, 50);
	Sprite* Lv = new Sprite("drawable/Ui/LV.bmp", { 0, 160 }, 50, 50);

	renderer->AddFixSprite(Hp);
	renderer->AddFixSprite(Dmg);
	renderer->AddFixSprite(Str);
	renderer->AddFixSprite(monsterHp);
	renderer->AddFixSprite(Lv);
	renderer->AddFixSprite(Floor);
}

void BattleScene::MonsterTurnMode()
{	
	renderer->ClearSprite();
	renderer->AddSprite(monsterAttackSprite);
	renderer->AddSprite(monsterTurnSprite);
	UpdateNumber();

	monsterAttackSprite->animation->PlayOnce([this]() {MonsterAttackFinish(); });
}

void BattleScene::PlayerTurnMode()
{
	ClearEvent();
	renderer->ClearSprite();

	renderer->AddSprite(playerSkillPanel);
	renderer->AddSprite(playerTurnSprite);
	UpdateNumber();

	AddInputEvent(Key_Q, [this]() {this->PlayerAttack(1); });
	AddInputEvent(Key_W, [this]() {this->PlayerAttack(2); });
	AddInputEvent(Key_E, [this]() {this->PlayerAttack(3); });
	AddInputEvent(Key_R, [this]() {this->PlayerAttack(4); });
}

void BattleScene::RewardMode(pair<Item*, int> reward)
{
	SceneManager& sceneManager = SceneManager::GetInstance();
	EDungeon dungeon = gameManager.GetCurrentDungeon();
	if (gameManager.GetCurrentDungeon() == DarkestDungeon && gameManager.IsBossStage()) {
		sceneManager.ChangeScene<EndingScene>();
	}
	int exp = 20 + dungeon * 20; // Weald = 20, Cove = 40, DD = 60
	player->AddExp(exp);

	renderer->ClearSprite();
	ClearEvent();

	Item* item = reward.first;
	int gold = reward.second;

	Sprite* itemSprite = new Sprite(item->GetImagePath(), { 155, 55 }, 95, 95);
	Sprite* goldSprite = new Sprite("drawable/Ui/Gold.bmp", { 255, 55 }, 95, 95);
	Sprite* panelSprite = new Sprite("drawable/Ui/Panel.bmp", { 140, 40 }, 220, 120);
	Sprite* textSprite = new Sprite("drawable/Ui/RewardText.bmp", { 140, 150 }, 220, 50);
	renderer->AddSprite(panelSprite);
	renderer->AddSprite(goldSprite);
	renderer->AddSprite(itemSprite);
	renderer->AddSprite(textSprite);
	renderer->DrawNumber(gold, { 255, 55 }, 45, 45);
	UpdateNumber();

	AddInputEvent(Key_1, [this]() {
		SceneManager& sceneManager = SceneManager::GetInstance();
		if (gameManager.IsBossStage()) {
			sceneManager.ChangeScene<MainScene>();
		}else sceneManager.ChangeScene<RoomScene>(); 
		});
}

void BattleScene::PlayerAttack(int skillIndex)
{
	ClearEvent();
	player->SetMonster(monster);
	renderer->AddSprite(playerSkill[skillIndex - 1]);
	playerSkill[skillIndex - 1]->animation->PlayOnce([this, skillIndex]() {PlayerAttackFinish(skillIndex); });
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
		pair<Item*, int> reward = monster->Die();
		RewardMode(reward);
	}
	else MonsterTurnMode();
}

void BattleScene::MonsterAttackFinish()
{
	SceneManager& sceneManager = SceneManager::GetInstance();
	monster->Attack();
	if (player->GetCurrentHealth() <= 0) {
		sceneManager.ChangeScene<GameOverScene>();
	}
	else {
		if (player->GetStress() >= 100) {
			player->SetAttliction();
		}
		else if (player->GetStress() >= 200) {
			sceneManager.ChangeScene<GameOverScene>();
		}
		else {
			this->PlayerTurnMode();
		}
	}
}

void BattleScene::UpdateNumber()
{
	renderer->DrawNumber(player->GetCurrentHealth(), { 50, 200 }, 25, 50);
	renderer->DrawNumber(player->GetStress(), { 150, 200 }, 25, 50);
	renderer->DrawNumber(player->GetDamage(), { 250, 200 }, 25, 50);
	renderer->DrawNumber(player->GetLevel(), { 50, 160 }, 25, 50);
	renderer->DrawNumber(gameManager.GetFloor(), {430, 250}, 25, 50);
	renderer->DrawNumber(monster->GetCurrentHealth() >= 0 ? monster->GetCurrentHealth() : 0, { 410, 0 }, 50, 50);
}

void BattleScene::Enter()
{
	DungeonScene::Enter();
	gameManager = GameManager::GetInstance();
	dungeon = gameManager.GetInstance().GetCurrentDungeon();

	player = gameManager.GetPlayer();
	MonsterSpawnHandle monsterSpawner;
	EDungeon dungeon = gameManager.GetCurrentDungeon();

	if (gameManager.IsBossStage())
	{
		monster = monsterSpawner.GetSpawnBossByDungeonLevel(dungeon);
	}
	else monster = monsterSpawner.GetSpawnMonsterByDungeonLevel(dungeon);

	ImportUiSprite();
	ImportMonsterSprite();
	ImportPlayerSprite();

	if (player->GetSpeed() < monster->GetSpeed()) {
		battleState = EMonsterAttack;
		MonsterTurnMode();
	}
	else {
		battleState = EPlayerAttack;
		PlayerTurnMode();
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
