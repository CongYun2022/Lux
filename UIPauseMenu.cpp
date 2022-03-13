#include "UIPauseMenu.h"
#include "Game.h"
#include "UIDialogBox.h"
#include <SDL/SDL.h>

UIPauseMenu::UIPauseMenu(Game* game)
	:UIScreen(game)
{
	mGame->SetState(Game::EPaused);
	SetRelativeMouseMode(false);
	SetTitle("PauseTitle");
	AddButton("ResumeButton", [this]() {
		Close();
	});
	AddButton("QuitButton", [this]() { 
		new UIDialogBox(mGame, "QuitText",
			[this]() {
				mGame->SetState(Game::EQuit);
		});
	});
}

UIPauseMenu::~UIPauseMenu()
{
	SetRelativeMouseMode(true);
	mGame->SetState(Game::EGameplay);
}

void UIPauseMenu::HandleKeyPress(int key)
{
	UIScreen::HandleKeyPress(key);
	
	if (key == SDLK_ESCAPE)
	{
		Close();
	}
}
