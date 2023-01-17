#include "Objects/Platform.h"

Platform CreatePlatform()
{
	Platform platform;

	platform.pos.x = 0;
	platform.pos.y = 0;

	platform.width = 140;
	platform.height = 30;

	platform.color = SKYBLUE;

	return platform;
}

void DrawPlatform(Platform& platform)
{
	DrawRectangle(static_cast<int>(platform.pos.x), static_cast<int>(platform.pos.y), static_cast<int>(platform.width), static_cast<int>(platform.height), platform.color);
}