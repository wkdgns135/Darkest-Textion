#pragma once
#include "Item/Item.h"
#include "Global/ProjectEnum.h"

class Player;

class Artifact : public Item 
{
protected:
	int amount;
	EArtifactRank rank;
public:
	~Artifact() {};
	virtual void Attach(Player& player) = 0;
	virtual void Detach(Player& player) = 0;
	inline int GetAmount() { return amount; };
	inline void SetAmount(int amount) { this->amount = amount; };
};