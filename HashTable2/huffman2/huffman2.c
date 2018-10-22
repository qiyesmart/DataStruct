//哈希桶
#include "huffman2.h"
//初始化
void  HashBucketInit(HashBucket *pHB, int capacity)
{
	pHB->array = (Node**)malloc(sizeof(Node *)*capacity);
	// 初始化 array 的值
	for (int i = 0; i < capacity; i++) {
		pHB->array[i] = NULL;	// 空链表
	}
	pHB->size = 0;
	pHB->capacity = capacity;
}
//销毁
void ListDestory(Node * first)
{
	Node *next;
	for (Node *cur = first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
}
void   HashBuckketDestory(HashBucket *pHB)
{
	//需要先释放哈希桶链表
	for (int i = 0; i < pHB->capacity; i++)
	{
		ListDestory(pHB->array[i]);
	}
	free(pHB->array);
}
//查找
//找到返回结点地址，否则返回NULL

Node * HashBucketSearch(HashBucket *pHB, Key key)
{
	int index = key%pHB->capacity;
	Node *cur = pHB->array[index];
	while (cur != NULL)
	{
		if (cur->key == key)
		{
			return cur;
		}
		cur = cur->next;
	}
	
	return NULL;
}

//插入（没有负载因子的概念）
int  HashBucketInsert(HashBucket *pHB, Key key);
void  EpandIfRequired(HashBucket *pHB, Key key)
{
	if (pHB->size < pHB->capacity)
	{
		return;
	}
	HashBucket  newHB;
	HashBucketInit(&newHB, pHB->capacity * 2);
	for (int i = 0; i < pHB->capacity; i++)
	{
		for (Node *cur = pHB->array[i]; cur != NULL; cur = cur->next)
		{
			HashBucketInsert(&newHB, cur->key);
		}
	}
	HashBuckketDestory(pHB);
	pHB->array = newHB.array;
	pHB->capacity = newHB.capacity;

}
int  HashBucketInsert(HashBucket *pHB, Key key)
{
	//扩容
	EpandIfRequired(pHB,key);
	if(HashBucketSearch(pHB, key) != NULL)
	{
		return 0;
	}

	int index = key%pHB->capacity;
	Node * first = pHB->array[index];
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = NULL;
	//头插
	newNode->next = first;
	pHB->array[index] = newNode;
	pHB->size++;
	//插入到第二个位置

	return 1;
}
//删除
int HashBucketRemove(HashBucket *pHB, Key key)
{
	int index = key%pHB->capacity;
	// pHB->array[index] 链表的第一个结点
	Node *prev = NULL;
	for (Node *cur = pHB->array[index]; cur != NULL; cur = cur->next) {
		if (cur->key == key) {
			if (prev == NULL) {
				pHB->array[index] = cur->next;
			}
			else {
				prev->next = cur->next;
			}
			free(cur);
			pHB->size--;
			return 1;
		}

		prev = cur;
	}

	return 0;
}
//测试


void Test()
{
	HashBucket hb;
	HashBucketInit(&hb,10);
	for (int i = 0; i < 100; i++)
	{
		HashBucketInsert(&hb, 0 + i * 10);
	}
	printf("%p\n", HashBucketSearch(&hb, 20));
	HashBucketRemove(&hb, 20);
	printf("%p\n", HashBucketSearch(&hb, 20));


}
int main()
{
	Test();
	system("pause");
	return 0;
}