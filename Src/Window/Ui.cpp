#include "Window/Ui.h"

Ui CreateUi()
{
	Ui ui;

	ui.isActive = true;

	return ui;
}

void DrawUi(Ui& ui, int lvCounter)
{
	if (ui.isActive == true)
	{
		DrawText(TextFormat("Level: %i", lvCounter), 0, 0, 40, WHITE);
	}
}