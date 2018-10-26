#pragma once
#include<stdio.h>
#include<Windows.h>
typedef  struct 
{
	int x;
	int y;
}Position;

#include"Stack.h"

#define ROWS (10)
#define COLS (10)

int game[ROWS][COLS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
};

int  IsExit(Position pos)
{
	if (pos.y == COLS - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CanPass(Position pos)
{
	//先判断是否越界
	if (pos.x < 0 || pos.x >= ROWS)
	{
		return 0;
	}
	if (pos.y < 0 || pos.y >= COLS)
	{
		return 0;
	}
	//在判断是否是路
	if (game[pos.x][pos.y] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void   PrintMaze()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (game[i][j] == 1)
			{
				printf("  ");
			}
			else if (game[i][j] == 0)
			{
				printf("█");
			}
			else
			{
				printf("⊙");
			}
		}
		printf("\n");
	}
}
void GoMaze()
{
	Stack stack;
	StackInit(&stack);
	Position entry = { 9, 2 };
	Position pos = entry;
	Position  nextPos;
	while (1)
	{
		//标记下这个位置走过了
		game[pos.x][pos.y] = 2;
		system("cls");
		PrintMaze();
		Sleep(300);
		//压栈，准备之后的回溯
		StackPush(&stack, pos);
		//当前是否走到出口
		//printf（走到出口了）exit
		if (IsExit(pos))
		{
			printf("找到出口了\n");
			return;
		}
		//按左上右下的顺序进行尝试，能不能走
	    nextPos = pos;
		nextPos.y -= 1;
		if (CanPass(nextPos))
		{
			pos = nextPos;
			continue;
		}
		nextPos = pos;
		nextPos.x -= 1;
		if (CanPass(nextPos))
		{
			pos = nextPos;
			continue;
		}
		nextPos = pos;
		nextPos.y += 1;
		if (CanPass(nextPos))
		{
			pos = nextPos;
			continue;
		}
		nextPos = pos;
		nextPos.x += 1;
		if (CanPass(nextPos))
		{
			pos = nextPos;
			continue;
		}
		//左上右下都不能走
		//回溯，pos=StackTop（）；StackPop（）	
		StackPop(&stack);
		pos = StackTop(&stack);
		StackPop(&stack);
	}
}

void test()
{
	GoMaze();
}