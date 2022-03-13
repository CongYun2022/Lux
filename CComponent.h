#pragma once
#include <cstdint>

class CComponent
{
public:
	// Constructor
	// (the lower the update order, the earlier the component updates)
	CComponent(class AActor* owner, int updateOrder = 100);
	// Destructor
	virtual ~CComponent();
	// Update this component by delta time
	virtual void Update(float deltaTime);
	// Process input for this component
	virtual void ProcessInput(const uint8_t* keyState) {}
	// Called when world transform changes
	virtual void OnUpdateWorldTransform() { }

	class AActor* GetOwner() { return mOwner; }
	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	// Owning actor
	class AActor* mOwner;
	// Update order of component
	int mUpdateOrder;
};
