#pragma once
#include "Artifact.h"



class SpeedStone : public Artifact
{
private:
	float amount;
public:
	SpeedStone();
	virtual string GetName() const override;
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};