#include "Item/Artifact/ArtifactDecorator.h"

ArtifactDecorator::ArtifactDecorator(Artifact* artifact) {
	wrappee = artifact;
}