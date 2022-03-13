#pragma once
#include "UIScreen.h"

class UIPauseMenu : public UIScreen
{
public:
	UIPauseMenu(class Game* game);
	~UIPauseMenu();

	void HandleKeyPress(int key) override;
};
