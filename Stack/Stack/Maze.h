#pragma once
#include <stdio.h>
#include <Windows.h>
#include "Stack.h"
#define   ROWS (6)
#define   COLS (6)

int game[ROWS][COLS] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 }
};
//迷宫问题
int IsExit(Position pos)
{
	if (pos.y = COLS - 1)
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
	if (pos.y < 0 || pos.y >= ROWS)
	{
		return 0;
	}
	if (game[pos.x][pos.y] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void  GoMaze()
{
	Stack stack;
	Position entry = { 5, 2 };
	Position  pos = entry;
	Position  nextPos;

	while (1)
	{
		//标记下这个位置走过
		game[pos.x][pos.y] = 2;
		//压栈，准备之后的回溯
		StackPush(&stack, pos);
		//当前是否走到出口
		//printf（走到出口了）exit
		if (IsExit(pos))
		{
			printf("找到出口了");
			return;
		}
		//按左上右下的顺序进行尝试，能不能走
		//如果左能走
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
		//上下左右都不能走
		StackPop(&stack);
		pos = StackTop(&stack);
		StackPop(&stack);;


	}
}
void test()
{
    /* int size = sizeof(array) / sizeof(array[0]);
     RPN(array,size);*/
	GoMaze();

}
