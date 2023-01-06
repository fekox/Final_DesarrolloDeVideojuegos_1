#pragma once

#include "raylib.h"

struct Enemy
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	Texture tex;
	Color color;
};

Enemy CreateEnemy();
void EnemyMovement();
void DrawEnemy();
