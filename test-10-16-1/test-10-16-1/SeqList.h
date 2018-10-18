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

//��ʼ��/����
void  SeqListInit(SeqListR *pSeq);
void  SeqListDestory(SeqListR *pSeq);
//��

void  SeqListPushFront(SeqListR *pSeq, DataType data);
void  SeqListPushBack(SeqListR *pSeq, DataType data);
void  SeqListInsrt(SeqListR *pSeq, int pos,DataType data);
//ɾ���������±�ɾ����
void  SeqListPopBack(SeqListR *pSeq);
void  SeqListPOpFront(SeqListR *pSeq);
void  SeqListErase(SeqListR *pSeq, int pos);
//ɾ������������ɾ����
//ɾ����һ��������data��
int SeqListRemove(SeqListR *pSeq, DataType data);
//ɾ�����������е�data
int SeqListRemoveAll(SeqListR *pSeq, DataType data);
//�鿴����
bool SeqListEmpty(const SeqListR *pSeq);
bool SeqListFull(const SeqListR *pSeq);
int SeqListSizey(const SeqListR *pSeq);
//����
int SeqListFind(const SeqListR *pSeq, DataType data);
//��ӡ
void SeqListPrint(SeqListR *pSeq);
//ѡ������
void SelectSortOP(SeqListR *pSeq);