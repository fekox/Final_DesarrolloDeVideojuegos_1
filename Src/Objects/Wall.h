#pragma once

#include "raylib.h"

struct Wall
{
	Vector2 pos;

	float width;
	float height;

	Texture tex;

	Color color;
};

Wall CreateWall();

void DrawWall(Wall& wall);
