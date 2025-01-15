#include "Character/Monster/DropItemObj.h"
#include "Item/Artifact/ArtifactDecorator.h"
#include "Item/Artifact/AncestalaArtifact.h"
#include "Item/Artifact/RareArtifact.h"
#include "Item/Artifact/ExpStone.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/SnakeOil.h"


Consumable* DropItemObj::GetConsumableItem(int index)
{
	int value = 100 / kindOfConsumable;

	if (index <= value * 1) return GetDamageBoost();
	else if (index <= value * 2) return GetHealthPotion();
	else return GetLaudanum();

	return nullptr;
}

Artifact* DropItemObj::GetArtifactItem(int rank, int index)
{
	int value = 100 % kindOfArtifact;
	int rankValue = 0;

	if (rank <= 60) rankValue = 0;
	else if (rank <= 90) rankValue = 1;
	else rankValue = 2;

	unique_ptr<Artifact> item;

	switch (value)
	{
	case 0:
		if (rankValue == 0) return new ExpStone();
		item = make_unique<ExpStone>();
		if (rankValue == 1) return new RareArtifact(move(item));
		return new AncestalaArtifact(move(item));
		break;

	case 1:
		if (rankValue == 0) return new HealthStone();
		item = make_unique<HealthStone>();
		if (rankValue == 1) return new RareArtifact(move(item));
		return new AncestalaArtifact(move(item));
		break;

	case 2:
		if (rankValue == 0) return new KnightsCrest();
		item = make_unique<KnightsCrest>();
		if (rankValue == 1) return new RareArtifact(move(item));
		return new AncestalaArtifact(move(item));
		break;

	case 3:
		if (rankValue == 0) return new SnakeOil();
		item = make_unique<SnakeOil>();
		if (rankValue == 1) return new RareArtifact(move(item));
		return new AncestalaArtifact(move(item));
		break;
	}

	return nullptr;
}
