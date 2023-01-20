#pragma once

#include "raylib.h"

enum class PlayerAnimations
{
	WalkRight,
	WalkLeft
};

struct Player
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	float gravity;
	float jumpForce;

	int deadCount;

	bool canJump;
	bool isAlive;
	bool win;
	bool isActive;
	bool canGoDown;

	bool goRight;
	bool goLeft;

	int actualAnim;

	Texture texWalkRight;
	Texture texWalkLeft;
	Texture texJumpRight;

	Rectangle frameRec;
	int frameCounter;
	int frameSpeed;

	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void InitAnimations(Player& player);

void DrawPlayer(Player& player, bool& pause);

void AddDead(Player& player);

bool PlayerWin(Player& player, int& lvCounter);