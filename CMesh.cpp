#include "CMesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "AActor.h"
#include "Game.h"
#include "Renderer.h"
#include "Texture.h"
#include "VertexArray.h"

CMesh::CMesh(AActor* owner)
	:CComponent(owner)
	,mMesh(nullptr)
	,mTextureIndex(0)
	,mVisible(true)
{
	mOwner->GetGame()->GetRenderer()->AddMeshComp(this);
}

CMesh::~CMesh()
{
	mOwner->GetGame()->GetRenderer()->RemoveMeshComp(this);
}

void CMesh::Draw(Shader* shader)
{
	if (mMesh)
	{
		// Set the world transform
		shader->SetMatrixUniform("uWorldTransform", 
			mOwner->GetWorldTransform());
		// Set specular power
		shader->SetFloatUniform("uSpecPower", mMesh->GetSpecPower());
		// Set the active texture
		Texture* t = mMesh->GetTexture(mTextureIndex);
		if (t)
		{
			t->SetActive();
		}
		// Set the mesh's vertex array as active
		VertexArray* va = mMesh->GetVertexArray();
		va->SetActive();
		// Draw
		glDrawElements(GL_TRIANGLES, va->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
	}
}
