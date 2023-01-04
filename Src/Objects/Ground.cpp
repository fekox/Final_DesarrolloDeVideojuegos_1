#include "Objects/Ground.h"

Ground CreateGround(int screenWidth, int screenHeight)
{
	Ground ground;

    ground.pos.x = static_cast<float>(screenWidth / screenWidth);
    ground.pos.y = static_cast<float>(screenHeight / 1.1f);

    ground.width = static_cast<float>(screenWidth);
    ground.height = 70;

    ground.color = YELLOW;

	return ground;
}

void DrawGround(Ground& ground)
{
    DrawRectangle(static_cast<int>(ground.pos.x), static_cast<int>(ground.pos.y), static_cast<int>(ground.width), static_cast<int>(ground.height), ground.color);
}