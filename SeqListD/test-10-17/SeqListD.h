#pragma once
#include<stdio.h>
typedef    int  DDateType;
typedef struct{
	DDateType *array;
	int         size;
	int          capacity;   //��������Ӧ��̬˳��������MAXSIZE

}  SeqListD;

void    SeqListDInit(SeqListD *seq);
void    SeqListDDestory(SeqListD *seq);