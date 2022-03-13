#pragma once
#include "CComponent.h"
#include "SoundEvent.h"
#include <vector>
#include <string>

class CAudio : public CComponent
{
public:
	CAudio(class AActor* owner, int updateOrder = 200);
	~CAudio();

	void Update(float deltaTime) override;
	void OnUpdateWorldTransform() override;

	SoundEvent PlayEvent(const std::string& name);
	void StopAllEvents();
private:
	std::vector<SoundEvent> mEvents2D;
	std::vector<SoundEvent> mEvents3D;
};