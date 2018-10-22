#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef  int Key;
typedef  struct Node{
	Key key;
	struct  Node   *next;
}Node;

typedef  struct{
	int size;
	int capacity;
	Node ** array;
}HashBucket;
//��ʼ��
void  HashBucketInit(HashBucket *pHB, int capacity);
//����
void   HashBuckketDestory(HashBucket *pHB);
//ɾ��
int HashBucketRemove(HashBucket *pHB, Key key);
//����
int  HashBucketInsert(HashBucket *pHB, Key key);
//����
Node * HashBucketSearch(HashBucket *pHB, Key key);

