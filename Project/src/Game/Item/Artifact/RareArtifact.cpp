#include "Item/Artifact/RareArtifact.h"
#include "Global/ProjectEnum.h"


RareArtifact::RareArtifact(unique_ptr<Artifact> artifact) : ArtifactDecorator(move(artifact))
{
	wrappee->SetRank(EArtifactRank::RARE);
}

void RareArtifact::Attach(Player& player)
{
	wrappee->SetAmount(wrappee->GetAmount() + 5);
	wrappee->Attach(player);
}

void RareArtifact::Detach(Player& player)
{
	wrappee->Detach(player);
	wrappee->SetAmount(wrappee->GetAmount() - 5);
}