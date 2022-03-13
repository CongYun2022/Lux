#pragma once
#include "CComponent.h"
#include "Math.h"

class CCamera : public CComponent
{
public:
	CCamera(class AActor* owner, int updateOrder = 200);
protected:
	void SetViewMatrix(const Matrix4& view);
};
