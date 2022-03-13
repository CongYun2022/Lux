#pragma once
#include "CMove.h"

class CBallMove : public CMove
{
public:
	CBallMove(class AActor* owner);

	void SetPlayer(AActor* player) { mPlayer = player; }
	void Update(float deltaTime) override;
protected:
	class AActor* mPlayer;
};