#include "Objects/Player.h"

Player createPlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 2.1f);
	player.pos.y = static_cast<float>(screenHeight / 1.2f);

	player.width = 40;
	player.height = 60;

	player.speed = 210;

	player.gravity = 0;

	player.jumpForce = 300;

	player.isJumping = false;
	player.isCollision = false;
	player.isActive = true;

	player.color = WHITE;

	return player;
}

void drawPlayer(Player& player)
{
	DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);
}

void playerCollisionLimit(Player& player, int screenWidth, int screenHeight)
{
	if (player.pos.x > screenWidth - player.width)
	{
		player.pos.x = screenWidth - player.width;
	}
	if (player.pos.x < screenWidth / screenWidth)
	{
		player.pos.x = static_cast<float>(screenWidth / screenWidth);
	}

	if (player.pos.y > screenHeight - player.height)
	{
		player.pos.y = screenHeight - player.height;
	}
	if (player.pos.y < screenHeight / screenHeight)
	{
		player.pos.y = static_cast<float>(screenHeight / screenHeight);
	}
}