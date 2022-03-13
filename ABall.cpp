#include "ABall.h"
#include "Game.h"
#include "Renderer.h"
#include "CMesh.h"
#include "Mesh.h"
#include "CBallMove.h"
#include "CAudio.h"

ABall::ABall(Game* game)
	:AActor(game)
	,mLifeSpan(2.0f)
{
	//SetScale(10.0f);
	CMesh* mc = new CMesh(this);
	Mesh* mesh = GetGame()->GetRenderer()->GetMesh("Assets/Sphere.gpmesh");
	mc->SetMesh(mesh);
	mMyMove = new CBallMove(this);
	mMyMove->SetForwardSpeed(1500.0f);
	mAudioComp = new CAudio(this);
}

void ABall::UpdateActor(float deltaTime)
{
	AActor::UpdateActor(deltaTime);
	
	mLifeSpan -= deltaTime;
	if (mLifeSpan < 0.0f)
	{
		SetState(EDead);
	}
}

void ABall::SetPlayer(AActor* player)
{
	mMyMove->SetPlayer(player);
}

void ABall::HitTarget()
{
	mAudioComp->PlayEvent("event:/Ding");
}
