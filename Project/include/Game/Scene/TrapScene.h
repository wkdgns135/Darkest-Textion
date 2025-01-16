#pragma once
#include <vector>
#include "Scene/DungeonScene.h"
#include "Character/Player/Player.h"
#include "GameManager.h"
#include "Character/Monster/DropItemObj.h"

enum ETrap
{
	Health = 0,
	Stress,
	Damage,
	Speed,
	Gold,
	ConsumableItem,
	ArtifactItem,
};

enum EWealdAntique
{
	AncientCoffin = 0, //오래된 관. 확률적 금화, 아무것도 없음
	TravellersTent, //여행자의 천막. 확률적 금화, 스트레스 증가, 아무것도 없음
	OldTree, //고목. 확률적 체력 감소, 아이템 드랍
	ShallowGrave, //얕은 무덤. 확률적 금화, 체력 감소
	TroublingEffigy, //꺼림칙한 형상. 확률적 체력 감소, 스트레스 증가
};

enum ECoveAntique
{
	ShipsFigurehead = 0, //배의 선수상. 확률적 스트레스 감소, 공격력 증가, 속도 증가
	BrackishTidePool, //소금물 웅덩이. 확률적 Hp 회복, 스트레스 감소, Hp 감소
	GiantOyster, //커다란 굴. 확률적 금화 획득, Hp 감소, 회피 증가, 아무것도 없음.
	FishIdol, //물고기 우상. 확률적 공격력 증가, 공격력 감소, 명중 감소, 회피 감소
	BarnacleCrustedChest, //따개비로 덮인 상자. 확률적 Hp 감소, 아무것도 없음
	EerieCoral, //으스스한 산호. 확률적 스트레스 감소, 스트레스 증가, 아무것도 없음.
	FishCarcass, //물고기 시체. 확률적 Hp 대량 감소.
	BasRelief, //얕은 돋을새김 조각품. 확률적 스트레스 대량 증가, Hp 감소.
};

enum EDarkestAntique
{
	AncestorsKnapsack = 0, //선조의 배낭. 대량의 금화 획득, 아이템 획득, 아티팩트 획득
	TranscendentTerror, //의식 너머의 공포. 스트레스 대량 증가.
	BanditsTrappedChest, //도적의 함정 상자. 대량의 Hp 감소.
	IronCrown, //아이언 크라운. 대량의 Hp 감소, 스트레스 증가
	LocusBeacon, //장소 신호대. 대량의 Hp 감소, 스트레스 증가
	CorruptedHarvest, //타락한 수확물. 스트레스 감소
	PlentifulBounty, //풍성한 수확물. Hp 증가.
	ThrongingHive, //밀집한 둥지. 확률적 Hp 감소
	WineCrate, //포도주 상자. 확률적 스트레스 감소, Hp 감소, 아무것도 없음
	PileOfStrangeBones, //이상한 뼈무더기. 확률적 Hp 감소, 스트레스 증가, 골드 획득
	WizenedShrew, //쭈글쭈글한 여인. 확률적 아티팩트 획득, Hp 감소, 아무것도 없음.
	HoodedShrew, //두건을 쓴 여인. 확률적 골드 획득, 스트레스 증가, Hp 감소, 아이템 획득, 아무것도 없음.
	DisturbingDiversion, //충격적인 오락. 확률적 스트레스 증가, Hp 감소, 아무것도 없음.
};

class TrapScene : public DungeonScene
{
public:
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

private:
	const int kindOfTrap = 7;
	const int kindOfWeald = 5;
	const int kindOfCove = 8;
	const int kindOfDarkest = 13;

	GameManager gameManager;
	DropItemObj* dropItem;
	Player* player;

	void SelectSearchOrMove();
	bool IsActiveEvent(EDungeon dungeonRank);
	void SelectRandomTrapByLevel();
	void PrintDetectAntique(vector<string> value);
	void RandomTrapEncounter();
	void ActionIncreaseEvent(int dungeonLevel);
	void ActionDecreaseEvent(int dungeonLevel);

	void AddOrDeleteItemEvent(bool isDelete);

	vector<string> GetInfoByAntiqueOfWeald();
	vector<string> GetInfoByAntiqueOfCove();
	vector<string> GetInfoByAntiqueOfDarkest();

	void PrintAvoidTrap(bool isNotEvent);
	void PrintMoveNext();
};