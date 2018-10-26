#pragma once
#include<assert.h>

typedef   Position  DataType;

#define MAXSIZE (100)

typedef   struct{
	DataType  array[MAXSIZE];
	int top;//起了个别名，含义还是size
}Stack;

void   StackInit(Stack *ps)
{
	ps->top = 0;
}

void   StackDestory(Stack *ps)
{
	ps->top = 0;
}

//栈中入放一个元素
void   StackPush(Stack *ps, DataType data)
{
	assert(ps->top < MAXSIZE);
	ps->array[ps->top++] = data;

}
//栈中弹出一个元素
void   StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;

}

//弹出栈顶元素
DataType   StackTop(const  Stack *ps)
{
	assert(ps->top > 0);
	return ps->array[ps->top - 1];
}

//返回栈的大小
int  StackSize(const Stack *ps)
{
	return  ps->top;
}
//返回栈是否为空
int StackEmpty(const Stack *ps)
{
	return ps->top == 0 ? 1 : 0;
}