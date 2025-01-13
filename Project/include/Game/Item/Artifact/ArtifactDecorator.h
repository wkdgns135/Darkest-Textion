#pragma once
#include "Artifact.h"

class ArtifactDecorator : public Artifact
{
protected:
	Artifact* wrappee;
public:
	ArtifactDecorator(Artifact* artifact);
	inline virtual ~ArtifactDecorator() { delete wrappee; };
};