#pragma once

#include "raylib.h"

#include "Objects/Player.h"

struct Ui
{
	bool isActive;
};

Ui CreateUi();

void DrawUi(Ui& ui, int lvCounter, Font gameFont, Player& player);