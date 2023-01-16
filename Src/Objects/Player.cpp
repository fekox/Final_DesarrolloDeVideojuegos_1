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

	player.actualAnim = 0;
	player.frameSpeed = 1;

	player.tex = LoadTexture("resources/Sprites/Penguin.png");

	player.color = WHITE;

	return player;
}

void InitAnimations(Player& player)
{
	int texLimitX = 0;
	int texLimitY = 0;

	int texLimitWidth = 0;
	int texLimitHeight = 0;

	texLimitWidth = 1032;
	texLimitHeight = 671;

	player.frameRec = Rectangle{ static_cast<float>(texLimitX), static_cast<float>(texLimitY), static_cast<float>(player.tex.width - texLimitWidth), static_cast<float>(player.tex.height - texLimitHeight) };
	player.frameCounter = 0;
	player.frameSpeed = 1;

	switch (player.actualAnim)
	{

		case static_cast<int>(PlayerAnimations::WalkRight):
		
		texLimitWidth = 1032;
		texLimitHeight = 671;

		player.frameRec = Rectangle{ static_cast<float>(texLimitX), static_cast<float>(texLimitY), static_cast<float>(player.tex.width - texLimitWidth), static_cast<float>(player.tex.height - texLimitHeight) };
		player.frameCounter = 0;
		player.frameSpeed = 1;

		break;

		case static_cast<int>(PlayerAnimations::Jump):

		break;

		case static_cast<int>(PlayerAnimations::Grab):

		break;

		default:
		break;
	}
}

void DrawPlayer(Player& player)
{
	int repoTexX = 50;
	int repoTexY = 50;

	if (IsKeyDown(KEY_A))
	{
		repoTexX = 50;
		repoTexY = 50;

		DrawTextureRec(player.tex, player.frameRec, Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY}, WHITE);
	}

	if (IsKeyDown(KEY_D))
	{
		repoTexX = 45;
		repoTexY = 50;

		DrawTextureRec(player.tex, player.frameRec, Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
	}

	if (!IsKeyDown(KEY_D) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S))
	{
		DrawTextureRec(player.tex, Rectangle{ 0.0f, 0.0f, static_cast<float>(player.tex.width - 1032), static_cast<float>(player.tex.height - 671)},
			Vector2{ player.pos.x - repoTexX, player.pos.y - repoTexY }, WHITE);
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