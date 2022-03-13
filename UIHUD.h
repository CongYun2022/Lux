#pragma once
#include "UIScreen.h"
#include <vector>

class UIHUD : public UIScreen
{
public:
	// (Lower draw order corresponds with further back)
	UIHUD(class Game* game);
	~UIHUD();

	void Update(float deltaTime) override;
	void Draw(class Shader* shader) override;
	
	void AddTargetComponent(class CTarget* tc);
	void RemoveTargetComponent(class CTarget* tc);
protected:
	void UpdateCrosshair(float deltaTime);
	void UpdateRadar(float deltaTime);
	
	class Texture* mHealthBar;
	class Texture* mRadar;
	class Texture* mCrosshair;
	class Texture* mCrosshairEnemy;
	class Texture* mBlipTex;
	class Texture* mRadarArrow;
	
	// All the target components in the game
	std::vector<class CTarget*> mTargetComps;
	// 2D offsets of blips relative to radar
	std::vector<Vector2> mBlips;
	// Adjust range of radar and radius
	float mRadarRange;
	float mRadarRadius;
	// Whether the crosshair targets an enemy
	bool mTargetEnemy;
};
