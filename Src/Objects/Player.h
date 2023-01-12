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
	bool isAlive;
	bool win;
	bool isActive;
	bool canGoDown;

	Texture tex;
	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void DrawPlayer(Player& player);

void LoseLife(Player& player);

bool IsAlive(Player& player);

bool PlayerWin(Player& player);