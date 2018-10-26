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
	//���ж��Ƿ�Խ��
	if (pos.x < 0 || pos.x >= ROWS)
	{
		return 0;
	}
	if (pos.y < 0 || pos.y >= COLS)
	{
		return 0;
	}
	//���ж��Ƿ���·
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
				printf("��");
			}
			else
			{
				printf("��");
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
		//��������λ���߹���
		game[pos.x][pos.y] = 2;
		system("cls");
		PrintMaze();
		Sleep(300);
		//ѹջ��׼��֮��Ļ���
		StackPush(&stack, pos);
		//��ǰ�Ƿ��ߵ�����
		//printf���ߵ������ˣ�exit
		if (IsExit(pos))
		{
			printf("�ҵ�������\n");
			return;
		}
		//���������µ�˳����г��ԣ��ܲ�����
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
		//�������¶�������
		//���ݣ�pos=StackTop������StackPop����	
		StackPop(&stack);
		pos = StackTop(&stack);
		StackPop(&stack);
	}
}

void test()
{
	GoMaze();
}