#pragma once
#include "Artifact.h"



class HealthStone : public Artifact
{
public:
	HealthStone();
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};