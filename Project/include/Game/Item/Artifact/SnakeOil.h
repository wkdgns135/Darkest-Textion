#pragma once
#include "Artifact.h"



class SnakeOil : public Artifact
{
public:
	SnakeOil();
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};