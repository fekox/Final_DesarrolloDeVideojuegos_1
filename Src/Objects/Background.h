#pragma once

#include "raylib.h"

struct Background
{
	Vector2 pos;

	float width;
	float height;

	Texture tex;
	Texture tex2;
};

Background CreateBackground();

void DrawBackground(Background& background, int lvCounter);