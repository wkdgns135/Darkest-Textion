#pragma once
#include "ArtifactDecorator.h"
#include <memory>

class RareArtifact : public ArtifactDecorator
{

public:
	RareArtifact(unique_ptr<Artifact> artifact);
	inline virtual string GetName() const override { return "Rare-" + wrappee->GetName(); };
	inline virtual int GetPrice() const override { return 100 + wrappee->GetPrice(); };
	inline virtual string GetImagePath() const override{ return wrappee->GetImagePath(); };
	virtual void Attach(Player& player) override;
	virtual void Detach(Player& player) override;
};