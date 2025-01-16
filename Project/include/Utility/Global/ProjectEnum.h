#pragma once

enum EKeyEvent {
	Key_1,
	Key_2,
	Key_3,
	Key_4,
	Key_ESC,
	Key_Q,
	Key_W,
	Key_E,
	Key_R,
	Key_I,
};


enum EArtifactRank
{
	COMMON,
	RARE,
	ANCESTAL
};

enum EAsciiArt {
	TitleAsciiArt,
	MainAsciiArt,
	SelectDungeonAsciiArt,
};

enum EDungeon {
	Weald,
	Cove,
	DarkestDungeon,
};
enum EItemName
{
	EExpStone =0,
	EHealthStone,
	EKnightsCrest,
	ESnkeOil,
	EDamageBoost,
	EHealthPotion,
	ELaudanum,
	EEnd
};
enum EAffliction
{
	Normal,
	Paranoid,
	Selfish,
	Irrational,
	DeathDoor
};