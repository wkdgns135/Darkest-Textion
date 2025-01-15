#include "GameManager.h"
#include "Scene/BattleScene.h"
#include "Character/Monster/MonsterSpawnHandle.h"

void BattleScene::ImportMonsterSprite()
{
	monsterAttack = new Sprite({ 250, 150 }, 100, 100);
	monsterAttack->AddAnimation({
		"drawable/SpriteSheet/Attack_0.bmp",
		"drawable/SpriteSheet/Attack_1.bmp",
		"drawable/SpriteSheet/Attack_2.bmp",
		"drawable/SpriteSheet/Attack_3.bmp",
		"drawable/SpriteSheet/Attack_4.bmp",
		"drawable/SpriteSheet/Attack_5.bmp"
		}, 0.1f);

	Sprite* monsterHp = new Sprite("drawable/Ui/MonsterHpText.bmp", {320, 0}, 100, 50);
	renderer->AddFixSprite(monsterHp);
	renderer->DrawNumber(monster->GetMaxHealth(), { 410, 0 }, 50, 50);
}

void BattleScene::ImportPlayerSprite()
{
	Sprite *playerSkill = new Sprite("drawable/PlayerSkill.bmp", { 10, 250 }, 350, 50);
	renderer->AddFixSprite(playerSkill);
}

void BattleScene::ImportUiSprite()
{
	
}

void BattleScene::MonsterTurn()
{
	monster->Attack();
	battleState = EMonsterAttack;
	monsterAttack->animation->PlayOnce([this]() {this->PlayerTurn(); });

}

void BattleScene::PlayerTurn()
{
	InitInputEvent();
	battleState = EStandbyInput;
}

void BattleScene::InitInputEvent()
{
	AddInputEvent(Key_A, [this]() {PlayerAttack(); });
}

void BattleScene::PlayerAttack()
{
	player->SetMonster(monster);
	player->Attack();
	battleState = EPlayerAttack;
	
	//TODO: 플레이어 공격 이펙트 애니메이션 재생 재생이 끝나면 몬스터 턴으로 전환
}

void BattleScene::Enter()
{
	DungeonScene::Enter();
	GameManager gameManager = GameManager::GetInstance();
	
	player = gameManager.GetPlayer();
	MonsterSpawnHandle monsterSpawner;
	monster = monsterSpawner.GetSpawnMonsterByDungeonLevel(gameManager.GetCurrentDungeon());

	ImportMonsterSprite();
	ImportPlayerSprite();
	ImportUiSprite();

	//if (player->GetSpeed() < monster->GetSpeed()) {
	//	battleState = EMonsterAttack;
	//	MonsterTurn();
	//}
	//else {
	//	battleState = EPlayerAttack;
	//	PlayerTurn();
	//}
	MonsterTurn();
}

void BattleScene::Update()
{
	DungeonScene::Update();
}

void BattleScene::Exit()
{
	DungeonScene::Exit();

	delete monsterAttack;
}
