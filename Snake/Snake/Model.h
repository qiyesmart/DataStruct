#pragma once

// 坐标结构体
typedef struct {
	int	x;
	int y;
}	Position;

// 链表的结点结构体
typedef struct Node {
	Position pos;
	struct Node *next;
}	Node;

// 蛇的前进方向
typedef enum {
	UP, RIGHT, DOWN, LEFT
}	Direction;

//蛇
typedef struct{
	Node *head;
	Direction   direction;
}Snake;

//游戏
typedef struct{
	Snake snake;
	Position food;
	int    width;
	int   height;
	int speed; //速度
	int score;//得分
}Game;

void GameInit(Game *pGame);
void GameDestroy(Game *pGame);
void FoodInit(Position *pFood, int width, int height, Snake *pSnake);


void SnakeAddHead(Snake *pSnake, Position nextPos);
void SnakeRemoveTail(Snake *pSnake);