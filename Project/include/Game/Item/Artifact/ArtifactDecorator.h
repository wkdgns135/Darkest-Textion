#pragma once
#include "Artifact.h"
#include <memory>

class ArtifactDecorator : public Artifact
{
protected:
	unique_ptr<Artifact> wrappee;
public:
	ArtifactDecorator(unique_ptr<Artifact> artifact);
	ArtifactDecorator(ArtifactDecorator& artifactDecorator);
	//inline virtual ~ArtifactDecorator() { delete wrappee; };
};