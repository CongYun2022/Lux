#include "CMove.h"
#include "AActor.h"

CMove::CMove(class AActor* owner, int updateOrder)
:CComponent(owner, updateOrder)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
{
	
}

void CMove::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		Quaternion rot = mOwner->GetRotation();
		float angle = mAngularSpeed * deltaTime;
		// Create quaternion for incremental rotation
		// (Rotate about up axis)
		Quaternion inc(Vector3::UnitZ, angle);
		// Concatenate old and new quaternion
		rot = Quaternion::Concatenate(rot, inc);
		mOwner->SetRotation(rot);
	}
	
	if (!Math::NearZero(mForwardSpeed) || !Math::NearZero(mStrafeSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		pos += mOwner->GetRight() * mStrafeSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}

}
