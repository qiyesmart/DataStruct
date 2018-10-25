#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//typedef   char  DataType;(����ƥ����ʹ��)
typedef   int  DataType;

#define MAXSIZE (100)

typedef   struct{
	DataType  array[MAXSIZE];
	int top;//���˸����������廹��size
}Stack;

void   StackInit(Stack *ps)
{
	ps->top = 0;
}

void   StackDestory(Stack *ps)
{
	ps->top = 0;
}

//ջ�����һ��Ԫ��
void   StackPush(Stack *ps,DataType data)
{
	assert(ps->top < MAXSIZE);
	ps->array[ps->top++] = data;

}
//ջ�е���һ��Ԫ��
void   StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;

}

//����ջ��Ԫ��
DataType   StackTop(const  Stack *ps)
{
	assert(ps->top > 0);
	return ps->array[ps->top - 1];
}

//����ջ�Ĵ�С
int  StackSize(const Stack *ps)
{
	return  ps->top;
}
//����ջ�Ƿ�Ϊ��
int StackEmpty(const Stack *ps)
{
	return ps->top == 0 ? 1 : 0;
}


//�沨�����ʽ����ض���

typedef enum{
	NUMBER,
	OPERATOR
}Type;

typedef enum{
	ADD, SUB, MUL, DIV, NOUSE
}OP;
typedef struct{
	Type type;
	int  number;
	OP   operator;
}Item;
Item array[] = {
	{
		NUMBER,
		178,
		NOUSE
	},
	{
		NUMBER,
		176,
		NOUSE
	},
	{
		OPERATOR,
		-1,
		ADD
	}
};


