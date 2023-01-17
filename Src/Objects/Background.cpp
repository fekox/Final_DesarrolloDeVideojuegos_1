#include "Objects/Background.h"

Background CreateBackground()
{
	Background background;

	background.pos.x = 0;
	background.pos.y = 0;

	background.width = 0;
	background.height = 0;

	background.centerTex = LoadTexture("resources/Sprites/Background.png");
	background.centerTex2 = LoadTexture("resources/Sprites/Background2.png");
	background.leftTex = LoadTexture("resources/Sprites/LeftBackground.png");
	background.rightTex = LoadTexture("resources/Sprites/RightBackground.png");

	return background;
}

void DrawCenterBackground(Background& background, int lvCounter)
{
	if (lvCounter % 2 == 0 )
	{
		DrawTexture(background.centerTex2, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
	}

	else
	{
		DrawTexture(background.centerTex, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
	}
}

void DrawLeftBackground(Background& background)
{
	DrawTexture(background.leftTex, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
}

void DrawRightBackgrounds(Background& background)
{
	DrawTexture(background.rightTex, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
}