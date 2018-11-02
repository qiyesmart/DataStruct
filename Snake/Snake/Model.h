#pragma once

// ����ṹ��
typedef struct {
	int	x;
	int y;
}	Position;

// ����Ľ��ṹ��
typedef struct Node {
	Position pos;
	struct Node *next;
}	Node;

// �ߵ�ǰ������
typedef enum {
	UP, RIGHT, DOWN, LEFT
}	Direction;

//��
typedef struct{
	Node *head;
	Direction   direction;
}Snake;

//��Ϸ
typedef struct{
	Snake snake;
	Position food;
	int    width;
	int   height;
	int speed; //�ٶ�
	int score;//�÷�
}Game;

void GameInit(Game *pGame);
void GameDestroy(Game *pGame);
void FoodInit(Position *pFood, int width, int height, Snake *pSnake);


void SnakeAddHead(Snake *pSnake, Position nextPos);
void SnakeRemoveTail(Snake *pSnake);