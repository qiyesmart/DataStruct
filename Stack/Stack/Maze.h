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
//�Թ�����
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
	//���ж��Ƿ�Խ��
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
		//��������λ���߹�
		game[pos.x][pos.y] = 2;
		//ѹջ��׼��֮��Ļ���
		StackPush(&stack, pos);
		//��ǰ�Ƿ��ߵ�����
		//printf���ߵ������ˣ�exit
		if (IsExit(pos))
		{
			printf("�ҵ�������");
			return;
		}
		//���������µ�˳����г��ԣ��ܲ�����
		//���������
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
		//�������Ҷ�������
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
