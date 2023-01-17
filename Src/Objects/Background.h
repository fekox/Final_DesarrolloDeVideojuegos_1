#pragma once

#include "raylib.h"

struct Background
{
	Vector2 pos;

	float width;
	float height;

	Texture centerTex;
	Texture centerTex2;
	Texture leftTex;
	Texture rightTex;
};

Background CreateBackground();

void DrawCenterBackground(Background& background, int lvCounter);

void DrawLeftBackground(Background& background); 

void DrawRightBackgrounds(Background& background);