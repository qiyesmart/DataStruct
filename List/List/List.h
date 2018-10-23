#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef   int DataType;

typedef struct ListNode{
	DataType data;
	struct  ListNode *next;
} ListNode;

//��ʼ��

void  ListInit(ListNode **ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}
//����
void ListDestory(ListNode **ppfirst)
{
	*ppfirst = NULL;
}
//
//ͷ��
void   ListPushFront(ListNode **ppfirst, DataType data);
//β��
void    ListPushBack(ListNode **ppfirst, DataType data);
//ͷɾ
void   ListPopFront(ListNode **ppfirst);

//βɾ
void  ListPopBack(ListNode **ppfirst);
//����

ListNode   *ListFind(ListNode *first, DataType data);

//�ڽ��ǰ�����루���pos�϶���������&&pos���ǿգ�
void   ListInsert(ListNode **ppfirst, ListNode *pos, DataType data);
//ɾ��ָ����㣨���pos�϶���������&&pos���ǿգ�
void  ListErase(ListNode **ppfirst, ListNode *pos);


