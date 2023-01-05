#pragma once

#include "raylib.h"

struct Platform
{
	Vector2 pos;

	float width;
	float height;

	bool isActive;

	Texture tex;

	Color color;
};

Platform CreatePlatform();

void DrawPlatform(Platform& platform);