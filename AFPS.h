#pragma once
#include "AActor.h"
#include "SoundEvent.h"

class AFPS : public AActor
{
public:
	AFPS(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keys) override;

	void Shoot();

	void SetFootstepSurface(float value);

	void SetVisible(bool visible);

	void FixCollisions();
private:
	class CMove* mMoveComp;
	class CAudio* mAudioComp;
	class CMesh* mMeshComp;
	class CFPSCamera* mCameraComp;
	class CBox* mBoxComp;
	// class AActor* mFPSModel;
	SoundEvent mFootstep;
	float mLastFootstep;
};
