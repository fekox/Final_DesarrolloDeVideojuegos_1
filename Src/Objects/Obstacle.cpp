#include "Objects/Obstacle.h"

Obstacle CreateObstacle()
{
	Obstacle obstacle;

	obstacle.pos.x = 0;
	obstacle.pos.y = 0;

	obstacle.width = 60;
	obstacle.height = 90;

	obstacle.speed = 200;

	obstacle.isActive = true;

	obstacle.tex;
	obstacle.color = BEIGE;

	return obstacle;
}

void ObstacleCollisionLimit(Obstacle& obstacle, int screenHeight)
{
	if (obstacle.pos.y > static_cast<float>(screenHeight))
	{
		obstacle.pos.y = static_cast<float>(screenHeight / screenHeight);
	}
}

void DrawObstacle(Obstacle& obstacle, Level& lv)
{
	if (lv.isLvActive == true)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), obstacle.color);
	}
}