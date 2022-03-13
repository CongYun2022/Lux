#include "CFPSCamera.h"
#include "AActor.h"

CFPSCamera::CFPSCamera(AActor* owner)
	:CCamera(owner)
	,mPitchSpeed(0.0f)
	,mMaxPitch(Math::Pi / 3.0f)
	,mPitch(0.0f)
{
}

void CFPSCamera::Update(float deltaTime)
{
	// Call parent update (doesn't do anything right now)
	CCamera::Update(deltaTime);
	// Camera position is owner position
	Vector3 cameraPos = mOwner->GetPosition();

	// Update pitch based on pitch speed
	mPitch += mPitchSpeed * deltaTime;
	// Clamp pitch to [-max, +max]
	mPitch = Math::Clamp(mPitch, -mMaxPitch, mMaxPitch);
	// Make a quaternion representing pitch rotation,
	// which is about owner's right vector
	Quaternion q(mOwner->GetRight(), mPitch);
	
	// Rotate owner forward by pitch quaternion
	Vector3 viewForward = Vector3::Transform(
		mOwner->GetForward(), q);
	// Target position 100 units in front of view forward
	Vector3 target = cameraPos + viewForward * 100.0f;
	// Also rotate up by pitch quaternion
	Vector3 up = Vector3::Transform(Vector3::UnitZ, q);
	
	// Create look at matrix, set as view
	Matrix4 view = Matrix4::CreateLookAt(cameraPos, target, up);
	SetViewMatrix(view);
}
