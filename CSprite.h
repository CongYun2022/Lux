#pragma once
#include "CComponent.h"
#include "SDL/SDL.h"

class CSprite : public CComponent
{
public:
	// (Lower draw order corresponds with further back)
	CSprite(class AActor* owner, int drawOrder = 100);
	~CSprite();

	virtual void Draw(class Shader* shader);
	virtual void SetTexture(class Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }

	void SetVisible(bool visible) { mVisible = visible; }
	bool GetVisible() const { return mVisible; }
protected:
	class Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
	bool mVisible;
};
