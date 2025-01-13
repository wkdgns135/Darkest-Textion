#pragma once
#include "Artifact.h"



class KnightsCrest : public Artifact
{
public:
	KnightsCrest();
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};