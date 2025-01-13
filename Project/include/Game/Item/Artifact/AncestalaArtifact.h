#pragma once
#include "ArtifactDecorator.h"

class AncestalaArtifact : public ArtifactDecorator
{

public:
	AncestalaArtifact(Artifact* artifact);
	inline virtual string GetName() const override { return "Ancestala-" + wrappee->GetName(); };
	inline virtual int GetPrice() const override { return 200 + wrappee->GetPrice(); };
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};