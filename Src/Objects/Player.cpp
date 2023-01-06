#include "Objects/Player.h"

#include "Window/LevelManager.h"

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

	player.canJump = true;
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

void PlayerCollisionLimitUpAndDown(Player& player, int screenHeight, Level& lv1, Level& lv2, Level& lv3, int& lvCounter)
{
	if (player.pos.y > static_cast<float>(screenHeight))
	{
		player.pos.y = static_cast<float>(screenHeight / screenHeight);

		lvCounter--;

		if (lvCounter == 1)
		{
			lv1.isLvActive = true;
			lv2.isLvActive = false;
			lv3.isLvActive = false;
		}

		if (lvCounter == 2)
		{
			lv1.isLvActive = false;
			lv2.isLvActive = true;
			lv3.isLvActive = false;
		}
	}

	if (player.pos.y < static_cast<float>(screenHeight / screenHeight))
	{
		player.pos.y = static_cast<float>(screenHeight);

		lvCounter++;

		if (lvCounter == 2)
		{
			lv1.isLvActive = false;
			lv2.isLvActive = true;
			lv3.isLvActive = false;
		}
		
		if (lvCounter == 3)
		{
			lv1.isLvActive = false;
			lv2.isLvActive = false;
			lv3.isLvActive = true;
		}

	}
}