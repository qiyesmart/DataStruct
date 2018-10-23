#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef   int DataType;

typedef struct ListNode{
	DataType data;
	struct  ListNode *next;
} ListNode;

//初始化

void  ListInit(ListNode **ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}
//销毁
void ListDestory(ListNode **ppfirst)
{
	*ppfirst = NULL;
}
//
//头插
void   ListPushFront(ListNode **ppfirst, DataType data);
//尾插
void    ListPushBack(ListNode **ppfirst, DataType data);
//头删
void   ListPopFront(ListNode **ppfirst);

//尾删
void  ListPopBack(ListNode **ppfirst);
//查找

ListNode   *ListFind(ListNode *first, DataType data);

//在结点前做插入（结点pos肯定在链表中&&pos不是空）
void   ListInsert(ListNode **ppfirst, ListNode *pos, DataType data);
//删除指定结点（结点pos肯定在链表中&&pos不是空）
void  ListErase(ListNode **ppfirst, ListNode *pos);


