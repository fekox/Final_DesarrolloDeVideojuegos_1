#include "Objects/Player.h"

#include "Window/LevelManager.h"

Player CreatePlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 2.1f);
	player.pos.y = static_cast<float>(screenHeight / 1.2f);

	player.width = 40;
	player.height = 60;

	player.speed = 250;

	player.gravity = 0;

	player.jumpForce = -650;

	player.deadCount = 0;

	player.canJump = true;
	player.isAlive = true;
	player.win = false;
	player.isActive = true;
	player.canGoDown = false;

	player.color = WHITE;

	return player;
}

void DrawPlayer(Player& player)
{
	DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);
}

void AddDead(Player& player)
{
	player.deadCount += 1;
}

bool PlayerWin(Player& player, int& lvCounter)
{
	if (lvCounter < 9)
	{
		return player.win == true;
	}

	else
	{
		return player.win == false;
	}
}