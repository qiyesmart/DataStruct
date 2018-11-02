#include "Model.h"
#include "View.h"
#include <stdbool.h>
#include <Windows.h>
#include<time.h>
#include<stdio.h>


//��whileѭ���ָ��һ�������ڣ�ÿ������Ҫ�������飺
//�жϰ����Ϳ��Ʒ���
//���ƶ����Ե�����-���ӷ�/����/������ʳ�����û�Ե���
//��Ϸ��������������ײǽ��/��ײ�Լ��ˣ�
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

//�Ƿ�Ե�ʳ��
static bool IsEaten(Position nextPos, Position food)
{
	return nextPos.x == food.x && nextPos.y == food.y;
}

//�Ƿ�ײǽ
static bool IsHitWall(Position nextPos, int width, int height)
{
	if (nextPos.x < 0) {
		// ײ�����
		return true;
	}

	if (nextPos.x >= width) {
		// ײ�ұ���
		return true;
	}

	if (nextPos.y < 0) {
		// ײ�ϱ���
		return true;
	}

	if (nextPos.y >= height) {
		// ײ�±���
		return true;
	}

	return false;
}

//�Ƿ�ײ���Լ�
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
		// ���Ʒ���
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
	printf("��ӭ����̰���ߵ�����\n");
	RunGame();
	system("pause");
	return 0;
	
}