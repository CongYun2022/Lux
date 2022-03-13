#pragma once
#include "AActor.h"

class APlane : public AActor
{
public:
	APlane(class Game* game);
	~APlane();
	class CBox* GetBox() { return mBox; }
private:
	class CBox* mBox;
};
