#pragma once
#include "ArtifactDecorator.h"
#include <memory>

class RareArtifact : public ArtifactDecorator
{

public:
	RareArtifact(unique_ptr<Artifact> artifact);
	virtual string GetName() const override { return "Rare-" + wrappee->GetName(); };
	virtual int GetPrice() const override { return 100 + wrappee->GetPrice(); };
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};