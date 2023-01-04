#include "Objects/Player.h"

Player CreatePlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 2.1f);
	player.pos.y = static_cast<float>(screenHeight / 1.2f);

	player.width = 40;
	player.height = 60;

	player.speed = 210;

	player.gravity = 0;

	player.jumpForce = 300;

	player.canJump = false;
	player.isCollision = false;
	player.isActive = true;

	player.color = WHITE;

	return player;
}

void DrawPlayer(Player& player)
{
	DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);
}

void PlayerCollisionLimitLeft(Player& player, Wall& wall)
{
	if (player.pos.x > wall.pos.x - wall.width)
	{
		player.pos.x = wall.pos.x - wall.width;
	}
}

void PlayerCollisionLimitRight(Player& player, Wall& wall)
{
	if (player.pos.x < wall.pos.x + wall.width)
	{
		player.pos.x = wall.pos.x + wall.width;
	}
}