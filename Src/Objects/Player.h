#pragma once

#include "raylib.h"

#include "Objects/Wall.h"

#include "Window/LevelManager.h"

struct Player
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	float gravity;
	float jumpForce;

	int lifes;

	int points;

	bool canJump;
	bool isActive;
	bool canGoDown;

	Texture tex;
	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void DrawPlayer(Player& player);

void PlayerCollisionLimitLeft(Player& player, Wall& wall);
void PlayerCollisionLimitRight(Player& player, Wall& wall);

void PlayerCollisionLimitUpAndDown(Player& player, int screenHeight, Level& lv1, Level& lv2, Level& lv3, Level& lv4, Level& lv5, Level& lv6, Level& lv7, int& lvCounter);