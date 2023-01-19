#include "Objects/Player.h"

#include "Window/LevelManager.h"

Player CreatePlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 2.1f);
	player.pos.y = static_cast<float>(screenHeight / 1.24f);

	player.width = 50;
	player.height = 80;

	player.speed = 250;

	player.gravity = 0;

	player.jumpForce = -650;

	player.deadCount = 0;

	player.canJump = true;
	player.isAlive = true;
	player.win = false;
	player.isActive = true;
	player.canGoDown = false;

	player.goRight = true;
	player.goLeft = false;

	player.actualAnim = 0;
	player.frameSpeed = 1;

	player.texWalkRight = LoadTexture("resources/Sprites/Penguin_Walk_Right.png");
	player.texWalkLeft = LoadTexture("resources/Sprites/Penguin_Walk_Left.png");

	player.color = WHITE;

	return player;
}

void InitAnimations(Player& player)
{
	int texLimitX = 0;
	int texLimitY = 0;

	int texLimitWidth = 0;
	int texLimitHeight = 0;

	switch (player.actualAnim)
	{
		case static_cast<int>(PlayerAnimations::WalkRight):
		
		texLimitWidth = 1070;
		texLimitHeight = 17;

		player.frameRec = Rectangle{ static_cast<float>(texLimitX), static_cast<float>(texLimitY), static_cast<float>(player.texWalkRight.width - texLimitWidth), static_cast<float>(player.texWalkRight.height - texLimitHeight) };
		player.frameCounter = 0;
		player.frameSpeed = 1;

		break;

		case static_cast<int>(PlayerAnimations::WalkLeft):

			texLimitWidth = 1071;
			texLimitHeight = 17;

			player.frameRec = Rectangle{ static_cast<float>(texLimitX), static_cast<float>(texLimitY), static_cast<float>(player.texWalkRight.width - texLimitWidth), static_cast<float>(player.texWalkRight.height - texLimitHeight) };
			player.frameCounter = 0;
			player.frameSpeed = 1;

			break;
	}
}

void DrawPlayer(Player& player, bool& pause)
{
	int texLimitWidth = 1070;
	int texLimitHeight = 17;

	int repoTexX = 0;
	int repoTexY = 0;

	if (pause == false)
	{
		if (IsKeyDown(KEY_A))
		{
			repoTexX = 50;
			repoTexY = 40;
			player.goRight = false;
			player.goLeft = true;

			DrawTextureRec(player.texWalkLeft, player.frameRec, Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
		}

		if (IsKeyDown(KEY_D))
		{
			repoTexX = 60;
			repoTexY = 40;
			player.goRight = true;
			player.goLeft = false;

			DrawTextureRec(player.texWalkRight, player.frameRec, Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
		}

		if (IsKeyDown(KEY_W))
		{
			if (player.goRight == true)
			{
				repoTexX = 60;
				repoTexY = 40;

				DrawTextureRec(player.texWalkRight, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkRight.width - texLimitWidth), static_cast<float>(player.texWalkRight.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}

			if (player.goLeft == true)
			{
				repoTexX = 55;
				repoTexY = 40;

				DrawTextureRec(player.texWalkLeft, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkLeft.width - texLimitWidth), static_cast<float>(player.texWalkLeft.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}
		}

		if (IsKeyDown(KEY_S))
		{
			if (player.goRight == true)
			{
				repoTexX = 60;
				repoTexY = 40;

				DrawTextureRec(player.texWalkRight, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkRight.width - texLimitWidth), static_cast<float>(player.texWalkRight.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}

			if (player.goLeft == true)
			{
				repoTexX = 55;
				repoTexY = 40;

				DrawTextureRec(player.texWalkLeft, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkLeft.width - texLimitWidth), static_cast<float>(player.texWalkLeft.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}
		}

		if (!IsKeyDown(KEY_D) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S))
		{
			if (player.goRight == true)
			{
				repoTexX = 60;
				repoTexY = 40;

				DrawTextureRec(player.texWalkRight, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkRight.width - texLimitWidth), static_cast<float>(player.texWalkRight.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}

			if (player.goLeft == true)
			{
				repoTexX = 55;
				repoTexY = 40;

				DrawTextureRec(player.texWalkLeft, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.texWalkLeft.width - texLimitWidth), static_cast<float>(player.texWalkLeft.height - texLimitHeight) },
					Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
			}

		}
	}

	DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.height), BLANK);
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