#pragma once
#include "Artifact.h"



class ExpStone : public Artifact
{
public:
	ExpStone();
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};