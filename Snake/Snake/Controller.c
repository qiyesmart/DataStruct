#include "Model.h"
#include "View.h"
#include <stdbool.h>
#include <Windows.h>
#include<time.h>
#include<stdio.h>


//大while循环分割成一个个周期，每个周期要做的事情：
//判断按键和控制方向
//蛇移动（吃到对象-》加分/加速/生成新食物，或者没吃到）
//游戏结束的条件（蛇撞墙了/蛇撞自己了）
static Position GetNextPosition( Snake *pSnake)
{
	Position nextPos = pSnake->head->pos;

	switch (pSnake->direction) {
	case UP:
		nextPos.y -= 1;
		break;
	case RIGHT:
		nextPos.x += 1;
		break;
	case DOWN:
		nextPos.y += 1;
		break;
	case LEFT:
		nextPos.x -= 1;
		break;
	}

	return nextPos;
}

//是否吃到食物
static bool IsEaten(Position nextPos, Position food)
{
	return nextPos.x == food.x && nextPos.y == food.y;
}

//是否撞墙
static bool IsHitWall(Position nextPos, int width, int height)
{
	if (nextPos.x < 0) {
		// 撞左边了
		return true;
	}

	if (nextPos.x >= width) {
		// 撞右边了
		return true;
	}

	if (nextPos.y < 0) {
		// 撞上边了
		return true;
	}

	if (nextPos.y >= height) {
		// 撞下边了
		return true;
	}

	return false;
}

//是否撞到自己
static bool IsHitSelf(Position nextPos, Snake *pSnake)
{
	for (Node *cur = pSnake->head->next; cur != NULL; cur = cur->next) {
		if (cur->pos.x == nextPos.x && cur->pos.y == nextPos.y) {
			return true;
		}
	}

	return false;
}

void RunGame()
{
	Game game;
	GameInit(&game);
	ViewInit(game.width, game.height);
	DisplayWall(game.width, game.height);
	DisplaySnake(&game.snake);

	while (1) 
	{
		// 控制方向
		if (GetAsyncKeyState(VK_UP) && game.snake.direction != DOWN) {
			game.snake.direction = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && game.snake.direction != UP) {
			game.snake.direction = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && game.snake.direction != RIGHT) {
			game.snake.direction = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && game.snake.direction != LEFT) {
			game.snake.direction = RIGHT;
		}

		Position nextPos = GetNextPosition(&game.snake);
		if (IsEaten(nextPos, game.food)) {
			SnakeAddHead(&game.snake, nextPos);
			game.score += 10;
			if (game.speed >= 100) {
				game.speed -= 10;
			}
			DisplayScore(game.score);
			FoodInit(&game.food, game.width, game.height, &game.snake);
		}
		else
		{
			SnakeRemoveTail(&game.snake);
			SnakeAddHead(&game.snake, nextPos);
		}

		if (IsHitWall(nextPos, game.width, game.height)) 
		{
			break;
		}

		if (IsHitSelf(nextPos, &game.snake)) 
		{
			break;
		}

		Sleep(game.speed);
	}

	GameDestroy(&game);
}
int main()
{
	srand((unsigned)time(NULL));
	printf("欢迎进入贪吃蛇的世界\n");
	RunGame();
	system("pause");
	return 0;
	
}