#include "Objects/Background.h"

Background CreateBackground()
{
	Background background;

	background.pos.x = 0;
	background.pos.y = 0;

	background.width = 0;
	background.height = 0;

	background.tex = LoadTexture("resources/Sprites/Background.png");
	background.tex2 = LoadTexture("resources/Sprites/Background2.png");

	return background;
}

void DrawBackground(Background& background, int lvCounter)
{
	if (lvCounter % 2 == 0 )
	{
		DrawTexture(background.tex2, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
	}

	else
	{
		DrawTexture(background.tex, static_cast<int>(background.pos.x), static_cast<int>(background.pos.y), WHITE);
	}
}