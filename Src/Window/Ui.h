#pragma once

#include "raylib.h"

struct Ui
{
	bool isActive;
};

Ui CreateUi();

void DrawUi(Ui& ui, int lvCounter);