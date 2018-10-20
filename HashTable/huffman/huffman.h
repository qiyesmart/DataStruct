#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef  int  Key;

typedef  enum
{
	EMPTY,
	EXIST,
	DELETED
}State;

typedef struct  Element{
	Key   key;
	State   state;
}Element;

typedef   int ( *HashFuncType)(Key key, int capacity);

typedef   struct  HashTable
{
	Element *table;
	int size;//���ݸ���
	int capacity;//����
	HashFuncType   hashFunc;//��ϣ����
}HashTable;

//��ʼ��
void   HashInit(HashTable *pHT, int capacity, HashFuncType hashFunc);
//����
void Destroy(HashTable *pHT);
//����
//һ������̽�ⷢ
int HashSearch1(HashTable *pHT, Key key);
//��������̽�ⷢ
int HashSearch2(HashTable *pHT, Key key);
// ����
//key�ظ����������
int HashInsert(HashTable *pHT, Key key);
//ɾ��
void HashTableRemove(HashTable *pHT, Key key);
