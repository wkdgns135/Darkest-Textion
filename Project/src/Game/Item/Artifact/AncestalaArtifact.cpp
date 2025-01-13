#include "Item/Artifact/AncestalaArtifact.h"

AncestalaArtifact::AncestalaArtifact(Artifact* artifact) : ArtifactDecorator(artifact)
{
	wrappee->SetRank(EArtifactRank::ANCESTAL);
}

void AncestalaArtifact::Attach(Player& player)
{
	wrappee->SetAmount(wrappee->GetAmount() + 2);
	wrappee->Attach(player);
}

void AncestalaArtifact::Detach(Player& player)
{
	wrappee->Detach(player);
}