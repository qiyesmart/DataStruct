#include "huffman.h"

//初始化

void   HashInit(HashTable *pHT, int capacity, HashFuncType hashFunc)
{
	pHT->table = (Element *)malloc(sizeof(Element)*capacity);
	assert(pHT->table);
	pHT->size = 0;
	pHT->capacity = capacity;
	pHT->hashFunc = hashFunc;

	for (int i = 0; i < capacity; i++)
	{
		pHT->table[i].state = EMPTY;
	}
}
//销毁
void Destory(HashTable *pHT)
{
	free(pHT->table);
}
//查找
int HashSearch1(HashTable *pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	while ((pHT->table[index].state) != EMPTY)
	{
		if (pHT->table[index].key == key&&pHT->table[index].state == EXIST)
		{
			return index;
		}
		else
			index = (index + 1) % pHT->capacity;
	}
	//没找到
	return 0;
}
//二次线性探测发
int HashSearch2(HashTable *pHT, Key key)
{
	int oindex = pHT->hashFunc(key, pHT->capacity);//i-1次查找的的元素下标
	int index = oindex;
	int i = 1;//i代表查找次数
	while ((pHT->table[index].state) != EMPTY)
	{
		if (pHT->table[index].key == key&&pHT->table[index].state == EXIST)
		{
			return index;
		}
		//二次探测法变化的位置
		index = (oindex + i*i) % pHT->capacity;
		i++;
	}
	//没找到
	return 0;
}
//插入
//key重复不允许插入
void ExpandIfRequired(HashTable *pHT)
{
	//不扩容
	if (pHT->size*10/pHT->capacity<7)
	{
		return;
	}
	//需要扩容
	int newCapacity = pHT->capacity * 2;
	HashTable newHT;
	HashInit(&newHT, newCapacity, pHT->hashFunc);
	for (int i = 0; i < pHT->capacity; i++)
    {
		if (pHT->table[i].state == EXIST)
		{
			HashInsert(&newHT, pHT->table[i].key);
		}
	}
	free(pHT->table);
	pHT->table = newHT.table;
	pHT->capacity = newHT.capacity;
	
}

int HashInsert(HashTable *pHT, Key key)
{
	ExpandIfRequired(pHT);
	int index = pHT->hashFunc(key, pHT->capacity);
	while (1)
	{
		if (pHT->table[index].key == key
			&&pHT->table[index].state == EXIST)
		{
			return 0;
		}
		if (pHT->table[index].state != EXIST)
		{
			pHT->table[index].key = key;
			pHT->table[index].state = EXIST;
			pHT->size++;
			return 1;
		}
		index = (index + 1) % pHT->capacity;
	}

	return 0;
}
//删除
void HashTableRemove(HashTable *pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	while ((pHT->table[index].state) !=EMPTY)
	{
		if (pHT->table[index].key == key&&pHT->table[index].state == EXIST)
		{
			pHT->table[index].state = DELETED;
			return 1;
		}
		else
			index = (index + 1) % pHT->capacity;
	}
	return 0;
}
//哈希函数
int hashFunc(Key key, int capacity)
{
	return key%capacity;
}

void   test()
{
	HashTable ht;
	HashInit(&ht, 10, hashFunc);

	HashInsert(&ht, 1);
	HashInsert(&ht, 11);
	HashInsert(&ht, 21);
	HashInsert(&ht, 31);
	HashInsert(&ht, 41);
	HashInsert(&ht, 51);
	HashInsert(&ht, 61);
	HashInsert(&ht, 71);
	HashInsert(&ht, 81);
	
	Destory(&ht);
}

int main()
{
	test();
	system("pause");
	return 0;
}