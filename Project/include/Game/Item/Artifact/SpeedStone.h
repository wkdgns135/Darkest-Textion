#pragma once
#include "Artifact.h"



class SpeedStone : public Artifact
{
private:
	float amount;
public:
	SpeedStone();
	inline virtual string GetName() const override { return name; };
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};