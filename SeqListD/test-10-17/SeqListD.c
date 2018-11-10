#include "SeqListD.h"

void SeqListDInit(SeqListD *seq)
{
	const int init_capacity = 5;
	assert(seq != NULL);
	assert(seq->array != NULL);
	seq->size = 0;
	seq->capacity = init_capacity;
	seq->array = (DDateType*)malloc(sizeof(DDateType)*init_capacity);
}
void    SeqListDDestory(SeqListD *seq)
{
	free(seq->array);
	seq->array = NULL;
	seq->size = 0;
	seq->capacity = 0;
}
//插入需要扩容/尾插
void ExpandIfRequired(SeqListD *seq)
{
	//不需要扩容
	if (seq->size < seq->capacity)
	{
		return;
	}
	//肯定要扩容
	int newCapacity = seq->capacity * 2;
	DDateType *newArray = (DDateType *)malloc(sizeof(DDateType)*newCapacity);
	assert(newArray);
	//搬移老的数据到新的数组
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i] = seq->array[i];
	}
	//释放老数组
	free(seq->array);
	//新数组放到顺序表结构体
	seq->array = newArray;
	//更新capacity
	seq->capacity = newCapacity;
}
void  SeqListDPushBack(SeqListD *seq,DDateType data)
{
	assert(seq);
	//需要考虑扩容
	ExpandIfRequired(seq);
	seq->array[seq->size++] = data;
}

void Test()
{
	SeqListD     seq;

	SeqListDInit(&seq);
}