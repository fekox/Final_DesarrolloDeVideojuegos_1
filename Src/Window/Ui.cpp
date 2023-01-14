#include "Window/Ui.h"

Ui CreateUi()
{
	Ui ui;

	ui.isActive = true;

	return ui;
}

void DrawUi(Ui& ui, int lvCounter, Font gameFont)
{
	if (ui.isActive == true)
	{
		DrawTextEx(gameFont, TextFormat("Level: %i", lvCounter), { static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 7) }, 60, 0, WHITE);
	}
}