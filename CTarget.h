#pragma once
#include "CComponent.h"

class CTarget : public CComponent
{
public:
	CTarget(class AActor* owner);
	~CTarget();
};
