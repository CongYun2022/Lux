#pragma once
#include "CCamera.h"

class CFPSCamera : public CCamera
{
public:
	CFPSCamera(class AActor* owner);

	void Update(float deltaTime) override;

	float GetPitch() const { return mPitch; }
	float GetPitchSpeed() const { return mPitchSpeed; }
	float GetMaxPitch() const { return mMaxPitch; }

	void SetPitchSpeed(float speed) { mPitchSpeed = speed; }
	void SetMaxPitch(float pitch) { mMaxPitch = pitch; }
private:
	// Rotation/sec speed of pitch
	float mPitchSpeed;
	// Maximum pitch deviation from forward
	float mMaxPitch;
	// Current pitch
	float mPitch;
};
