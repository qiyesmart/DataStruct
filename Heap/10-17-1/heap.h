#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct  Heap{
	int array[100];
	int    size;
} Heap;
//堆的初始化
void HeapInit(Heap *pH, int source[], int size);
//创建堆
void HeapMake1(Heap *pH);//递归
void HeapMake2(Heap *pH);//非递归
//堆的删除
void HeapPop(Heap *pH);
//堆的插入
void HeapPush(Heap *pH, int data);
//堆打印
void Print(const Heap *pH);
void Print2(int array[], int size);
