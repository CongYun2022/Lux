#pragma once
#include "UIScreen.h"

class UIDialogBox : public UIScreen
{
public:
	// (Lower draw order corresponds with further back)
	UIDialogBox(class Game* game, const std::string& text,
		std::function<void()> onOK);
	~UIDialogBox();
};
