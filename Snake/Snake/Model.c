#include "Model.h"
#include "View.h"
#include <stdlib.h>
#include <stdbool.h>


static void SnakeInit(Snake *pSnake)
{
	pSnake->direction = RIGHT;
	pSnake->head = NULL;
	for (int i = 0; i < 3; i++) {
		int x = 3 + i;
		int y = 3;
		Node *node = (Node *)malloc(sizeof(Node));
		node->pos.x = x;
		node->pos.y = y;

		node->next = pSnake->head;
		pSnake->head = node;
	}
}
//�ж�ʳ������Ƿ��ص����������������ѡ�񲼶�ֵ��
 static bool IsOverlapSnake(int x, int  y, Snake *pSnake)
{
	for (Node *cur = pSnake->head; cur != NULL; cur = cur->next)
	{
		if (x == cur->pos.x&&y == cur->pos.y)
		{
			return true;
		}
	}
	return false;
}
//����ʳ��
void FoodInit(Position *pFood,int width,int height, Snake *pSnake)
{
	//ʳ�ﲻ�ܺ����ص������ܳ�ǽ���������
	int x;
	int y;
	do
	{
		x = rand() % width;
		y = rand() % height;
	} while (IsOverlapSnake(x, y, pSnake));
	
	pFood->x = x; 
	pFood->y = y;
	DisplayFood(x, y);

}
void GameInit(Game *pGame)
{
	pGame->width = 28;
	pGame->height = 27;
	SnakeInit(&pGame->snake);
	FoodInit(&pGame->food,pGame->width,pGame->height,&pGame->snake);
	
	pGame->speed = 300;//ÿ�����ڼ��300ms
	pGame->score = 0;
}
//������
static void SnakeDestroy(Snake *pSnake)
{
	Node *cur, *next;
	for (cur = pSnake->head; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
}

void GameDestroy(Game *pGame)
{
	SnakeDestroy(&pGame->snake);
}
//����ͷ���
void SnakeAddHead(Snake *pSnake, Position nextPos)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->pos.x = nextPos.x;
	node->pos.y = nextPos.y;

	node->next = pSnake->head;
	pSnake->head = node;

	DisplaySnakeBlock(nextPos.x, nextPos.y);
}

void  SnakeRemoveTail(Snake *pSnake)
{
	// ɾ�����һ����㣬��Ҫ�ҵ������ڶ���
	// ����Ҫȥ�ж��������м�����㣬��Ϊһ��ʼ���� 3 ��
	Node *cur;
	for (cur = pSnake->head; cur->next->next != NULL; cur = cur->next) {
	}
	CleanSnakeBlock(cur->next->pos.x, cur->next->pos.y);
	free(cur->next);
	cur->next = NULL;
}

