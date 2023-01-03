#pragma once

#include "raylib.h"

#include "Objects/Wall.h"

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

	bool isJumping;
	bool isCollision;
	bool isActive;

	Texture tex;
	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void DrawPlayer(Player& player);

void PlayerCollisionLimitLeft(Player& player, Wall& wall);
void PlayerCollisionLimitRight(Player& player, Wall& wall);