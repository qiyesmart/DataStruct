#pragma once
#include<stdio.h>
typedef    int  DDateType;
typedef struct{
	DDateType *array;
	int         size;
	int          capacity;   //容量，对应静态顺序表里面的MAXSIZE

}  SeqListD;

void    SeqListDInit(SeqListD *seq);
void    SeqListDDestory(SeqListD *seq);