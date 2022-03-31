#include "CBallMove.h"
#include "AActor.h"
#include "Game.h"
#include "SPhys.h"
#include "ATarget.h"
#include "ABall.h"

CBallMove::CBallMove(AActor* owner)
	:CMove(owner)
{
}

void CBallMove::Update(float deltaTime)
{
	// Construct segment in direction of travel
	const float segmentLength = 30.0f;
	Vector3 start = mOwner->GetPosition();
	Vector3 dir = mOwner->GetForward();
	Vector3 end = start + dir * segmentLength;

	// Create line segment
	LineSegment l(start, end);

	// Test segment vs world
	SPhys* phys = mOwner->GetGame()->GetPhysWorld();
	SPhys::CollisionInfo info;
	// (Don't collide vs player)
	if (phys->SegmentCast(l, info) && info.mActor != mPlayer)
	{
		// If we collided, reflect the ball about the normal
		dir = Vector3::Reflect(dir, info.mNormal);
		mOwner->RotateToNewForward(dir);
		// Did we hit a target?
		ATarget* target = dynamic_cast<ATarget*>(info.mActor);
		if (target)
		{
			static_cast<ABall*>(mOwner)->HitTarget();
		}
	}

	// Base class update moves based on forward speed
	CMove::Update(deltaTime);
}
