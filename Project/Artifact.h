#pragma once
#include "Item.h"

class Player;

enum EArtifactRank
{
	COMMON,
	UNCOMMON,
	RARE,
	VERY_RARE,
	TROPHY,
	ANCESTAL
};

class Artifact : Item 
{
protected:
	string name;
	EArtifactRank rank;
	float price;
public:
	~Artifact() {};
	virtual string GetName() const = 0;
	virtual void Attach(Player& player) = 0;
	virtual void Detach(Player& player) = 0;
};