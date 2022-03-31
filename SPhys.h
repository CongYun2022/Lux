#pragma once
#include <vector>
#include <functional>
#include "Math.h"
#include "Collision.h"

class SPhys
{
public:
	SPhys(class Game* game);

	// Used to give helpful information about collision results
	struct CollisionInfo
	{
		// Point of collision
		Vector3 mPoint;
		// Normal at collision
		Vector3 mNormal;
		// Component collided with
		class CBox* mBox;
		// Owning actor of component
		class AActor* mActor;
	};

	// Test a line segment against boxes
	// Returns true if it collides against a box
	bool SegmentCast(const LineSegment& l, CollisionInfo& outColl);

	// Tests collisions using naive pairwise
	void TestPairwise(std::function<void(class AActor*, class AActor*)> f);
	// Test collisions using sweep and prune
	void TestSweepAndPrune(std::function<void(class AActor*, class AActor*)> f);

	// Add/remove box components from world
	void AddBox(class CBox* box);
	void RemoveBox(class CBox* box);
private:
	class Game* mGame;
	std::vector<class CBox*> mBoxes;
};
