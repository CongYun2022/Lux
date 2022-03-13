#pragma once
#include "AActor.h"

class ABall : public AActor
{
public:
	ABall(class Game* game);

	void UpdateActor(float deltaTime) override;
	void SetPlayer(AActor* player);

	void HitTarget();
private:
	class CAudio* mAudioComp;
	class CBallMove* mMyMove;
	float mLifeSpan;
};
