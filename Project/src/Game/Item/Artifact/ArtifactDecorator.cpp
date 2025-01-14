#include "Item/Artifact/ArtifactDecorator.h"

ArtifactDecorator::ArtifactDecorator(unique_ptr<Artifact> artifact) {
	wrappee = move(artifact);
}

ArtifactDecorator::ArtifactDecorator(ArtifactDecorator& artifactDecorator)
{
	wrappee = move(artifactDecorator.wrappee);
}
