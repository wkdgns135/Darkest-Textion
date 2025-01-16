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
	AncientCoffin = 0, //������ ��. Ȯ���� ��ȭ, �ƹ��͵� ����
	TravellersTent, //�������� õ��. Ȯ���� ��ȭ, ��Ʈ���� ����, �ƹ��͵� ����
	OldTree, //���. Ȯ���� ü�� ����, ������ ���
	ShallowGrave, //���� ����. Ȯ���� ��ȭ, ü�� ����
	TroublingEffigy, //����Ģ�� ����. Ȯ���� ü�� ����, ��Ʈ���� ����
};

enum ECoveAntique
{
	ShipsFigurehead = 0, //���� ������. Ȯ���� ��Ʈ���� ����, ���ݷ� ����, �ӵ� ����
	BrackishTidePool, //�ұݹ� ������. Ȯ���� Hp ȸ��, ��Ʈ���� ����, Hp ����
	GiantOyster, //Ŀ�ٶ� ��. Ȯ���� ��ȭ ȹ��, Hp ����, ȸ�� ����, �ƹ��͵� ����.
	FishIdol, //����� ���. Ȯ���� ���ݷ� ����, ���ݷ� ����, ���� ����, ȸ�� ����
	BarnacleCrustedChest, //������� ���� ����. Ȯ���� Hp ����, �ƹ��͵� ����
	EerieCoral, //�������� ��ȣ. Ȯ���� ��Ʈ���� ����, ��Ʈ���� ����, �ƹ��͵� ����.
	FishCarcass, //����� ��ü. Ȯ���� Hp �뷮 ����.
	BasRelief, //���� �������� ����ǰ. Ȯ���� ��Ʈ���� �뷮 ����, Hp ����.
};

enum EDarkestAntique
{
	AncestorsKnapsack = 0, //������ �賶. �뷮�� ��ȭ ȹ��, ������ ȹ��, ��Ƽ��Ʈ ȹ��
	TranscendentTerror, //�ǽ� �ʸ��� ����. ��Ʈ���� �뷮 ����.
	BanditsTrappedChest, //������ ���� ����. �뷮�� Hp ����.
	IronCrown, //���̾� ũ���. �뷮�� Hp ����, ��Ʈ���� ����
	LocusBeacon, //��� ��ȣ��. �뷮�� Hp ����, ��Ʈ���� ����
	CorruptedHarvest, //Ÿ���� ��Ȯ��. ��Ʈ���� ����
	PlentifulBounty, //ǳ���� ��Ȯ��. Hp ����.
	ThrongingHive, //������ ����. Ȯ���� Hp ����
	WineCrate, //������ ����. Ȯ���� ��Ʈ���� ����, Hp ����, �ƹ��͵� ����
	PileOfStrangeBones, //�̻��� ��������. Ȯ���� Hp ����, ��Ʈ���� ����, ��� ȹ��
	WizenedShrew, //�ޱ��ޱ��� ����. Ȯ���� ��Ƽ��Ʈ ȹ��, Hp ����, �ƹ��͵� ����.
	HoodedShrew, //�ΰ��� �� ����. Ȯ���� ��� ȹ��, ��Ʈ���� ����, Hp ����, ������ ȹ��, �ƹ��͵� ����.
	DisturbingDiversion, //������� ����. Ȯ���� ��Ʈ���� ����, Hp ����, �ƹ��͵� ����.
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