#pragma once
#include "CComponent.h"
#include "Collision.h"

class CBox : public CComponent
{
public:
	CBox(class AActor* owner, int updateOrder = 100);
	~CBox();

	void OnUpdateWorldTransform() override;

	void SetObjectBox(const AABB& model) { mObjectBox = model; }
	const AABB& GetWorldBox() const { return mWorldBox; }

	void SetShouldRotate(bool value) { mShouldRotate = value; }
private:
	AABB mObjectBox;
	AABB mWorldBox;
	bool mShouldRotate;
};
