#pragma   once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE (100)
typedef  int DataType;

typedef   struct  SeqList{
	DataType      array[MAXSIZE];
	int          size;

} SeqListR;

//初始化/销毁
void  SeqListInit(SeqListR *pSeq);
void  SeqListDestory(SeqListR *pSeq);
//增

void  SeqListPushFront(SeqListR *pSeq, DataType data);
void  SeqListPushBack(SeqListR *pSeq, DataType data);
void  SeqListInsrt(SeqListR *pSeq, int pos,DataType data);
//删除（根据下标删除）
void  SeqListPopBack(SeqListR *pSeq);
void  SeqListPOpFront(SeqListR *pSeq);
void  SeqListErase(SeqListR *pSeq, int pos);
//删除（根据数据删除）
//删除第一个遇到的data，
int SeqListRemove(SeqListR *pSeq, DataType data);
//删除遇到的所有的data
int SeqListRemoveAll(SeqListR *pSeq, DataType data);
//查看属性
bool SeqListEmpty(const SeqListR *pSeq);
bool SeqListFull(const SeqListR *pSeq);
int SeqListSizey(const SeqListR *pSeq);
//查找
int SeqListFind(const SeqListR *pSeq, DataType data);
//打印
void SeqListPrint(SeqListR *pSeq);
//选择排序
void SelectSortOP(SeqListR *pSeq);