#include "CBox.h"
#include "AActor.h"
#include "Game.h"
#include "SPhys.h"

CBox::CBox(AActor* owner, int updateOrder)
	:CComponent(owner, updateOrder)
	,mObjectBox(Vector3::Zero, Vector3::Zero)
	,mWorldBox(Vector3::Zero, Vector3::Zero)
	,mShouldRotate(true)
{
	mOwner->GetGame()->GetPhysWorld()->AddBox(this);
}

CBox::~CBox()
{
	mOwner->GetGame()->GetPhysWorld()->RemoveBox(this);
}

void CBox::OnUpdateWorldTransform()
{
	// Reset to object space box
	mWorldBox = mObjectBox;
	// Scale
	mWorldBox.mMin *= mOwner->GetScale();
	mWorldBox.mMax *= mOwner->GetScale();
	// Rotate (if we want to)
	if (mShouldRotate)
	{
		mWorldBox.Rotate(mOwner->GetRotation());
	}
	// Translate
	mWorldBox.mMin += mOwner->GetPosition();
	mWorldBox.mMax += mOwner->GetPosition();
}
