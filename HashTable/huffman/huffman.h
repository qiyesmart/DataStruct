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
	int size;//数据个数
	int capacity;//容量
	HashFuncType   hashFunc;//哈希函数
}HashTable;

//初始化
void   HashInit(HashTable *pHT, int capacity, HashFuncType hashFunc);
//销毁
void Destroy(HashTable *pHT);
//查找
//一次线性探测发
int HashSearch1(HashTable *pHT, Key key);
//二次线性探测发
int HashSearch2(HashTable *pHT, Key key);
// 插入
//key重复不允许插入
int HashInsert(HashTable *pHT, Key key);
//删除
void HashTableRemove(HashTable *pHT, Key key);
