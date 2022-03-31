#include "CBox.h"
#include "AActor.h"
#include "Game.h"
#include "SPhys.h"
#include "CTarget.h"
#include "Math.h"
#include "Game.h"
#include "UIHUD.h"

CTarget::CTarget(AActor * owner)
	:CComponent(owner)
{
	mOwner->GetGame()->GetHUD()->AddTargetComponent(this);
}

CTarget::~CTarget()
{
	mOwner->GetGame()->GetHUD()->RemoveTargetComponent(this);
}
