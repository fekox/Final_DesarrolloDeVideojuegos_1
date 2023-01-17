#include "Objects/Obstacle.h"

Obstacle CreateObstacle()
{
	Obstacle obstacle;

	obstacle.pos.x = 0;
	obstacle.pos.y = -150;

	obstacle.width = 40;
	obstacle.height = 150;

	obstacle.speed = 400;

	obstacle.isActive = true;

	obstacle.tex = LoadTexture("resources/Sprites/Stalactite.png");
	obstacle.color = BLANK;

	return obstacle;
}

void ObstacleCollisionLimit(Obstacle& obstacle, int screenHeight)
{
	if (obstacle.pos.y > static_cast<float>(screenHeight))
	{
		obstacle.pos.y = -150;
	}
}

void DrawObstacle(Obstacle& obstacle, Level& lv)
{
	int repoTexX = 40;
	int repoTexY = 10;

	if (lv.isLvActive == true)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), obstacle.color);

		DrawTexture(obstacle.tex, static_cast<int>(obstacle.pos.x - repoTexX), static_cast<int>(obstacle.pos.y - repoTexY), WHITE);
	}
}