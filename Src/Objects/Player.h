#pragma once

#include "raylib.h"

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

	Texture tex;
	Color color;
};

Player createPlayer(int screenWidth, int screenHeight);

void drawPlayer(Player& player);

void playerCollisionLimit(Player& player, int screenWidth, int screenHeight);