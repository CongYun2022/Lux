#include "APlane.h"
#include "Game.h"
#include "Renderer.h"
#include "CMesh.h"
#include "CBox.h"
#include "Mesh.h"

APlane::APlane(Game* game)
	:AActor(game)
{
	SetScale(10.0f);
	CMesh* mc = new CMesh(this);
	Mesh* mesh = GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh");
	mc->SetMesh(mesh);
	// Add collision box
	mBox = new CBox(this);
	mBox->SetObjectBox(mesh->GetBox());

	game->AddPlane(this);
}

APlane::~APlane()
{
	GetGame()->RemovePlane(this);
}
