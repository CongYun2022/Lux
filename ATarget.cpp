#include "ATarget.h"
#include "Game.h"
#include "Renderer.h"
#include "CMesh.h"
#include "CBox.h"
#include "Mesh.h"
#include "CTarget.h"

ATarget::ATarget(Game* game)
	:AActor(game)
{
	//SetScale(10.0f);
	SetRotation(Quaternion(Vector3::UnitZ, Math::Pi));
	CMesh* mc = new CMesh(this);
	Mesh* mesh = GetGame()->GetRenderer()->GetMesh("Assets/Target.gpmesh");
	mc->SetMesh(mesh);
	// Add collision box
	CBox* bc = new CBox(this);
	bc->SetObjectBox(mesh->GetBox());
	new CTarget(this);

}
