#include "CComponent.h"
#include "AActor.h"

CComponent::CComponent(AActor* owner, int updateOrder)
	:mOwner(owner)
	,mUpdateOrder(updateOrder)
{
	// Add to actor's vector of components
	mOwner->AddComponent(this);
}

CComponent::~CComponent()
{
	mOwner->RemoveComponent(this);
}

void CComponent::Update(float deltaTime)
{
}
