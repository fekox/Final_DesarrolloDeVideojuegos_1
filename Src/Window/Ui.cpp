#include "Window/Ui.h"

Ui CreateUi()
{
	Ui ui;

	ui.isActive = true;

	return ui;
}

void DrawUi(Ui& ui, int lvCounter, Font gameFont, Player& player)
{
	if (ui.isActive == true)
	{
		DrawTextEx(gameFont, TextFormat("Level: %i", lvCounter), { static_cast<float>(GetScreenWidth() / GetScreenWidth()), static_cast<float>(GetScreenHeight() / 10) }, 60, 0, WHITE);
		
		DrawTextEx(gameFont, TextFormat("Deads: %i", player.deadCount), { static_cast<float>(GetScreenWidth() / GetScreenWidth()), static_cast<float>(GetScreenHeight() / 4) }, 60, 0, WHITE);
	}
}