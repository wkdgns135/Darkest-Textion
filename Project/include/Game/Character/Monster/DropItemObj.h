#pragma once

#include "Item/Consumable/DamageBoost.h"
#include "Item/Consumable/HealthPotion.h"
#include "Item/Consumable/Laudanum.h"

class Artifact;

class DropItemObj
{
public:
	Consumable* GetConsumableItem(int index);
	Artifact* GetArtifactItem(int rank, int index);

private:
	const int kindOfConsumable = 3;
	const int kindOfArtifact = 4;

	inline Consumable* GetDamageBoost() { return new DamageBoost(); }
	inline Consumable* GetHealthPotion() { return new HealthPotion(); }
	inline Consumable* GetLaudanum() { return new Laudanum(); }
};
