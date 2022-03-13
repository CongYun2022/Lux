#pragma once
#include "CComponent.h"

class CMove : public CComponent
{
public:
	// Lower update order to update first
	CMove(class AActor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;
	
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	float GetStrafeSpeed() const { return mStrafeSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	void SetStrafeSpeed(float speed) { mStrafeSpeed = speed; }
protected:
	float mAngularSpeed;
	float mForwardSpeed;
	float mStrafeSpeed;
};
