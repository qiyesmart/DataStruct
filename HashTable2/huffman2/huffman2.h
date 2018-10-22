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
//初始化
void  HashBucketInit(HashBucket *pHB, int capacity);
//销毁
void   HashBuckketDestory(HashBucket *pHB);
//删除
int HashBucketRemove(HashBucket *pHB, Key key);
//插入
int  HashBucketInsert(HashBucket *pHB, Key key);
//查找
Node * HashBucketSearch(HashBucket *pHB, Key key);

