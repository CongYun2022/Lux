#include "CCamera.h"
#include "AActor.h"
#include "Renderer.h"
#include "Game.h"
#include "SAudio.h"

CCamera::CCamera(AActor* owner, int updateOrder)
	:CComponent(owner, updateOrder)
{
}

void CCamera::SetViewMatrix(const Matrix4& view)
{
	// Pass view matrix to renderer and audio system
	Game* game = mOwner->GetGame();
	game->GetRenderer()->SetViewMatrix(view);
	game->GetAudioSystem()->SetListener(view);
}
