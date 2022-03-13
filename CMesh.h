#pragma once
#include "CComponent.h"
#include <cstddef>

class CMesh : public CComponent
{
public:
	CMesh(class AActor* owner);
	~CMesh();
	// Draw this mesh component
	virtual void Draw(class Shader* shader);
	// Set the mesh/texture index used by mesh component
	virtual void SetMesh(class Mesh* mesh) { mMesh = mesh; }
	void SetTextureIndex(size_t index) { mTextureIndex = index; }

	void SetVisible(bool visible) { mVisible = visible; }
	bool GetVisible() const { return mVisible; }
protected:
	class Mesh* mMesh;
	size_t mTextureIndex;
	bool mVisible;
};
