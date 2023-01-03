#include "Objects/Platform.h"

Platform CreatePlatform(int screenWidth, int screenHeight)
{
	Platform platform;

	platform.pos.x = static_cast<float>(screenWidth / screenWidth);
	platform.pos.y = static_cast<float>(screenHeight / 1.1f);

	platform.width = static_cast<float>(screenWidth);
	platform.height = 70;

	platform.color = YELLOW;

	return platform;
}

void DrawPlatform(Platform& platform)
{
	DrawRectangle(static_cast<int>(platform.pos.x), static_cast<int>(platform.pos.y), static_cast<int>(platform.width), static_cast<int>(platform.height), platform.color);
}