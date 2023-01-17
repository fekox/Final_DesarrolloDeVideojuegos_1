#include "Objects/Wall.h"

Wall CreateWall()
{
	Wall wall;

	wall.pos.x = 0;
	wall.pos.y = 0;

	wall.width = 0;
	wall.height = 0;

	wall.color = BLANK;

	return wall;
}

void DrawWall(Wall& wall)
{
	DrawRectangle(static_cast<int>(wall.pos.x), static_cast<int>(wall.pos.y), static_cast<int>(wall.width), static_cast<int>(wall.height), wall.color);
}